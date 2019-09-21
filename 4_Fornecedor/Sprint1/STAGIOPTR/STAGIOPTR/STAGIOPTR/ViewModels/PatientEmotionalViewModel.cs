using STAGIOPTR.Database;
using STAGIOPTR.Models;

namespace STAGIOPTR.ViewModels
{
    public class PatientEmotionalViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public PatientEmotionalViewModel(Patient Patient)
        {
            this.Patient = Patient;
        }

    }
}
