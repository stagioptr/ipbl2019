using STAGIOPTR.Database;
using STAGIOPTR.Models;

namespace STAGIOPTR.ViewModels
{
    public class PatientSleepViewModel: BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { _patient = value; }
        }


        public PatientSleepViewModel(Patient Patient)
        {
            this.Patient = Patient;
        }

    }
}
