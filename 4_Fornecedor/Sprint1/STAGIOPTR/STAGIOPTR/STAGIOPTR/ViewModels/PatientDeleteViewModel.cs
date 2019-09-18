using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientDeleteViewModel : BaseViewModel
    {
        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        DatabaseConnection database = new DatabaseConnection();

        public Command DeletePatientCommand { get; }

        public PatientDeleteViewModel()
        {

        }

        public PatientDeleteViewModel(Patient Patient)
        {
            this.Patient = Patient;
            DeletePatientCommand = new Command(ExecuteDeletePatientCommand);
        }

        public void ExecuteDeletePatientCommand()
        {
            this.database.DeletePatient(this.Patient);
        }
    }
}
