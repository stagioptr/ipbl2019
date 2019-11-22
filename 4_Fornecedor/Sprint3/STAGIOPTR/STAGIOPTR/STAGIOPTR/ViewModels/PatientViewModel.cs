using Plugin.Messaging;
using STAGIOPTR.Database;
using STAGIOPTR.Helpers;
using STAGIOPTR.Models;
using System;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private User _userLogged;

        public User UserLogged
        {
            get { return _userLogged; }
            set { SetProperty( ref _userLogged, value); }
        }

        private bool _validationButton;

        public bool ValidationButton
        {
            get { return _validationButton; }
            set { SetProperty(ref _validationButton, value); }
        }

        private bool _validationSettings;

        public bool  ValidationSettings
        {
            get { return _validationSettings; }
            set { SetProperty(ref _validationSettings, value); }
        }



        public Patient Patient { get; }
        public Command LogoutCommand { get; set; }
        public Command ShowFeedingCommand { get; set; }
        public Command ShowSleepCommand { get; set; }
        public Command ShowEmotionalCommand { get; set; }
        public Command AlterPatientCommand { get; }
        public Command DelPatientCommand { get; }
        public Command EmergencyCommand { get; set; }

        public PatientViewModel()
        {
            User User = database.GetLoggedUser();
            this.Patient = database.GetPatientPerId(User.IdPatient);
            UserLogged = User;
            this.SetAccessLevel();
            LogoutCommand = new Command(this.Logout);
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
            EmergencyCommand = new Command(ExecuteEmergencyCommand);
        }

        public PatientViewModel(Patient patient)
        {
            Patient = patient;
            UserLogged = database.GetLoggedUser();
            this.SetAccessLevel();
            Debug.WriteLine("Button: " + this.ValidationButton);
            Debug.WriteLine("Settings: " + this.ValidationSettings);
            LogoutCommand = new Command(this.Logout);
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
            EmergencyCommand = new Command(ExecuteEmergencyCommand);
        }

        public PatientViewModel(User User)
        {
            this.Patient = database.GetPatientPerId(User.IdPatient);
            UserLogged = User;
            this.SetAccessLevel();
            Debug.WriteLine("Button: " + this.ValidationButton);
            Debug.WriteLine("Settings: " + this.ValidationSettings);
            LogoutCommand = new Command(this.Logout);
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
            EmergencyCommand = new Command(ExecuteEmergencyCommand);
        }

        private async void ExecuteShowFeedingCommand()
        {
            if(this.ValidationSettings)
                await PushAsync<PatientFeedingViewModel>(Patient);
        }

        private async void ExecuteShowSleepCommand()
        {
            if(this.ValidationSettings)
                await PushAsync<PatientSleepViewModel>(Patient);
        }

        private async void ExecuteShowEmotionalCommand()
        {
            if(this.ValidationSettings)
                await PushAsync<PatientEmotionalViewModel>(Patient);
        }

        private async void ExecuteAlterPatientCommand()
        {
            if(this.ValidationSettings)
                await PushAsync<PatientUpdateViewModel>(Patient);
        }

        private async void ExecuteDelPatientCommand()
        {
            if(this.ValidationSettings)
                await PushAsync<PatientDeleteViewModel>(Patient);
        }

        private async void ExecuteEmergencyCommand()
        {
            if (this.ValidationButton)
            {
                var phoneDialer = CrossMessaging.Current.PhoneDialer;
                if (phoneDialer.CanMakePhoneCall && !String.IsNullOrWhiteSpace(Patient.EmergencyPhone.ToString()))
                    phoneDialer.MakePhoneCall(Patient.EmergencyPhone.ToString());
            }
        }

        private void SetAccessLevel()
        {
            this.ValidationButton = false;
            this.ValidationSettings = false;
            if (this.UserLogged.AccessLevel == 3)
                this.ValidationButton = true;
            if(this.UserLogged.AccessLevel != 4 && this.UserLogged.AccessLevel != 3)
                this.ValidationSettings = true;
        }
    }
}
