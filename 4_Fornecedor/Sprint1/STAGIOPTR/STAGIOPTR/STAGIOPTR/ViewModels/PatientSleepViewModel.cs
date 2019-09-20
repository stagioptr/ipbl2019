using STAGIOPTR.Models;

namespace STAGIOPTR.ViewModels
{
    public class PatientSleepViewModel: BaseViewModel
    {
        public Patient Patient { get; }

        public PatientSleepViewModel(Patient Patient)
        {
            this.Patient = Patient;
        }
    }
}
