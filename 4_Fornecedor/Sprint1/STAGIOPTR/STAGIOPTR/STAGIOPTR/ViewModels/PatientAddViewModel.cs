using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientAddViewModel : BaseViewModel
    {
        private Patient _patient;
        DatabaseConnection database = new DatabaseConnection();
        public Command AddPatientCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public PatientAddViewModel()
        {
            Patient = new Patient();
            AddPatientCommand = new Command(ExecuteAddPatientCommand);
        }

        public void ExecuteAddPatientCommand()
        {
            this.database.InsertPatients(this.Patient);
        }

    }
}
