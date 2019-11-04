using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class LoginViewModel:BaseViewModel
    {
        private Patient _patient;
        DatabaseConnection database = new DatabaseConnection();
        public Command LoginPatientCommand { get; }
        public Command RegisterPatientCommand { get; }

        public string email;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private string _erros;

        public string Errors
        {
            get { return _erros; }
            set { SetProperty(ref _erros, value); }
        }


        public LoginViewModel()
        {
            Patient = new Patient();
            LoginPatientCommand = new Command(ExecuteLoginPatientCommandAsync);
            RegisterPatientCommand = new Command(ExecuteRegisterPatientCommandAsync);
        }

        private async void ExecuteLoginPatientCommandAsync()
        {
            this.Patient = this.database.getPatientPerEmail(this.email);
            if (this.Patient == null)
            {
                this.Errors = "Paciente não cadastrado!";
            }
            else
            {
                await PushAsync<PatientViewModel>(Patient);
            }
        }

        private async void ExecuteRegisterPatientCommandAsync()
        {
            await PushAsync<PatientAddViewModel>();
        }
    }
}
