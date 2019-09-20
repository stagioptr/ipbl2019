using STAGIOPTR.Models;

namespace STAGIOPTR.ViewModels
{
    public class PatientEmotionalViewModel:BaseViewModel
    {
        public Patient Patient { get; }

        public PatientEmotionalViewModel(Patient Patient)
        {
            this.Patient = Patient;
        }
    }
}
