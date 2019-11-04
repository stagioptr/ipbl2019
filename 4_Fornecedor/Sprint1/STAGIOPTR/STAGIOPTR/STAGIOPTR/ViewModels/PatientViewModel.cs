using STAGIOPTR.Models;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientViewModel : BaseViewModel
    {
        public Patient Patient { get; }

        public Command ShowFeedingCommand { get; set; }
        public Command ShowSleepCommand { get; set; }
        public Command ShowEmotionalCommand { get; set; }
        public Command AlterPatientCommand { get; }
        public Command DelPatientCommand { get; }


        public PatientViewModel(Patient patient)
        {
            Patient = patient;
            ShowFeedingCommand = new Command(ExecuteShowFeedingCommand);
            ShowSleepCommand = new Command(ExecuteShowSleepCommand);
            ShowEmotionalCommand = new Command(ExecuteShowEmotionalCommand);
            AlterPatientCommand = new Command(ExecuteAlterPatientCommand);
            DelPatientCommand = new Command(ExecuteDelPatientCommand);
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
    }
}
