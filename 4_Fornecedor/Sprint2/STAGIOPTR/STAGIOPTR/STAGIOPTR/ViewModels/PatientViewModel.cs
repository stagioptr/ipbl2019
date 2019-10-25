using Plugin.Messaging;
using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        public Patient Patient { get; }
        public Command LogoutCommand { get; set; }
        public Command ShowFeedingCommand { get; set; }
        public Command ShowSleepCommand { get; set; }
        public Command ShowEmotionalCommand { get; set; }
        public Command AlterPatientCommand { get; }
        public Command DelPatientCommand { get; }
        public Command CallCommand { get; set; }

        public PatientViewModel(Patient patient)
        {
            Patient = patient;
            LogoutCommand = new Command(this.Logout);
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
            CallCommand = new Command(ExecuteCallCommand);
        }

        public PatientViewModel(User User)
        {
            this.Patient = database.GetPatientPerId(User.IdPatient);
            LogoutCommand = new Command(this.Logout);
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
            CallCommand = new Command(ExecuteCallCommand);
        }

        private async void ExecuteShowFeedingCommand()
        {
            await PushAsync<PatientFeedingViewModel>(Patient);
        }

        private async void ExecuteShowSleepCommand()
        {
            await PushAsync<PatientSleepViewModel>(Patient);
        }

        private async void ExecuteShowEmotionalCommand()
        {
            await PushAsync<PatientEmotionalViewModel>(Patient);
        }

        private async void ExecuteAlterPatientCommand()
        {
            await PushAsync<PatientUpdateViewModel>(Patient);
        }

        private async void ExecuteDelPatientCommand()
        {
            await PushAsync<PatientDeleteViewModel>(Patient);
        }

        private async void ExecuteCallCommand()
        {
            var phoneDialer = CrossMessaging.Current.PhoneDialer;
            if (phoneDialer.CanMakePhoneCall && !String.IsNullOrWhiteSpace(Patient.EmergencyPhone.ToString()))
                phoneDialer.MakePhoneCall(Patient.EmergencyPhone.ToString());
        }
    }
}
