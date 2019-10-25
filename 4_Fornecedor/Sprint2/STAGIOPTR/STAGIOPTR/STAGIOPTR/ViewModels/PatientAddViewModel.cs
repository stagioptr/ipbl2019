using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;
using System.Diagnostics;

namespace STAGIOPTR.ViewModels
{
    public class PatientAddViewModel : BaseViewModel
    {
        private Patient _patient;
        DatabaseConnection database = new DatabaseConnection();
        public Command AddPatientCommand { get; }
        public Command LogoutCommand { get; set; }
        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public PatientAddViewModel()
        {
            Patient = new Patient();
            LogoutCommand = new Command(this.Logout);
            AddPatientCommand = new Command(ExecuteAddPatientCommand);
        }

        public void ExecuteAddPatientCommand()
        {
            this.database.InsertPatients(this.Patient);
            User User = new User
            {
                Name = this.Patient.Name ,
                CPF = this.Patient.CPF,
                Email = this.Patient.Email,
                Password = "paciente",
                AccessLevel = 3,
                IdPatient = 0
            };
            this.database.InsertUsers(User);
            Application.Current.MainPage.Navigation.PopAsync();
        }

    }
}
