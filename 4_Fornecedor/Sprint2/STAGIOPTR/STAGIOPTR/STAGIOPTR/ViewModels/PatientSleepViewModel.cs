using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientSleepViewModel: BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private ObservableCollection<Sleep> _sleep;

        public ObservableCollection<Sleep> Sleep
        {
            get { return _sleep; }
            set { SetProperty(ref _sleep, value); }
        }

        private Patient _patient;

        public Command AddSleepCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { _patient = value; }
        }


        public PatientSleepViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Sleep = new ObservableCollection<Sleep>();
            AddSleepCommand = new Command(ExecuteAddSleepCommand);
            this.LoadAsync();
        }

        private async void ExecuteAddSleepCommand()
        {
            await PushAsync<SleepAddViewModel>(this.Patient);
        }

        public override async Task LoadAsync()
        {
            var sleeps = await database.getSleep(this.Patient.Id);
            this.Sleep.Clear();
            foreach (var sleep in sleeps)
            {
                this.Sleep.Add(sleep);
            }
        }

    }
}
