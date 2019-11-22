using STAGIOPTR.Models;
using STAGIOPTR.Database;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    class PatientFeedingViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private Feeding _feeding;

        public Feeding Feeding
        {
            get { return _feeding; }
            set { SetProperty(ref _feeding, value); }
        }

        private ObservableCollection<Feeding> _feedings;
        public ObservableCollection<Feeding> Feedings
        {
            get { return _feedings; }
            set { SetProperty(ref _feedings, value); }
        }

        public Patient Patient { get; }

        public Command AddFeedingCommand { get; }
        public Command LogoutCommand { get; set; }
        public Command LoadFeedingsCommand { get; }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }


        public PatientFeedingViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Feedings = new ObservableCollection<Feeding>();
            LogoutCommand = new Command(this.Logout);
            this.Feeding = new Feeding();
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddFeedingCommand = new Command(ExecuteAddFeedingCommand);
            LoadFeedingsCommand = new Command(LoadAsyncList);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var foods = database.ListFeeding(this.Patient.Id);
            this.Feedings.Clear();
            foreach (var food in foods)
            {
                this.Feedings.Add(food);
            }
            this.IsLoading = false;
        }

        private async void ExecuteAddFeedingCommand()
        {
            this.Feeding.IdPatient = this.Patient.Id;
            await PushAsync<FeedingAddFoodViewModel>(this.Feeding);
        }
    }
}
