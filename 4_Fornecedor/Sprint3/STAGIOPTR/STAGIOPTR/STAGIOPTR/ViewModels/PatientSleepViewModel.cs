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

        public Command AddSleepCommand { get; }
        public Command LogoutCommand { get; set; }
        public Command LoadSleepsCommand { get; }

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { _patient = value; }
        }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public PatientSleepViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Sleep = new ObservableCollection<Sleep>();
            LogoutCommand = new Command(this.Logout);
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddSleepCommand = new Command(ExecuteAddSleepCommand);
            LoadSleepsCommand = new Command(LoadAsyncList);
        }

        private async void ExecuteAddSleepCommand()
        {
            await PushAsync<SleepAddViewModel>(this.Patient);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var sleeps = database.GetSleep(this.Patient.Id);
            this.Sleep.Clear();
            foreach (var sleep in sleeps)
            {
                this.Sleep.Add(sleep);
            }
            this.IsLoading = false;
        }

    }
}
