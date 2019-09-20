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
        private Feeding _feeding;

        public Feeding Feeding
        {
            get { return _feeding; }
            set { SetProperty(ref _feeding, value); }
        }


        private ObservableCollection<Feeding> _feedings;
        DatabaseConnection database = new DatabaseConnection();
        public ObservableCollection<Feeding> Feedings
        {
            get { return _feedings; }
            set { SetProperty(ref _feedings, value); }
        }

        public Patient Patient { get; }

        public Command AddFeedingCommand { get; }

        public PatientFeedingViewModel(Patient Patient)
        {
            Debug.WriteLine("AQUI");
            this.Feedings = new ObservableCollection<Feeding>();
            this.Feeding = new Feeding();
            AddFeedingCommand = new Command(ExecuteAddFeedingCommand);
            this.LoadAsync();
            this.Patient = Patient;
        }

        public override async Task LoadAsync()
        {
            var foods = await database.ListFeeding();
            this.Feedings.Clear();
            foreach (var food in foods)
            {
                this.Feedings.Add(food);
            }
        }

        private async void ExecuteAddFeedingCommand()
        {
            this.Feeding.IdPatient = this.Patient.Id;
            await PushAsync<FeedingAddFoodViewModel>(this.Feeding);
        }
    }
}
