using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientEmotionalViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        private ObservableCollection<Emotional> _emotional;

        public ObservableCollection<Emotional> Emotional
        {
            get { return _emotional; }
            set { SetProperty(ref _emotional, value); }
        }

        private Patient _patient;
        public Command LogoutCommand { get; set; }
        public Command AddEmotionalCommand { get; }

        public Command LoadEmotionalsCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public PatientEmotionalViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Emotional = new ObservableCollection<Emotional>();
            LogoutCommand = new Command(this.Logout);
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddEmotionalCommand = new Command(ExecuteAddEmotionalCommand);
            LoadEmotionalsCommand = new Command(LoadAsyncList);
        }

        private async void ExecuteAddEmotionalCommand()
        {
            await PushAsync<EmotionalAddViewModel>(this.Patient);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var emotionals = await database.GetEmotional(this.Patient.Id);
            this.Emotional.Clear();
            foreach (var emotional in emotionals)
            {
                this.Emotional.Add(emotional);
            }
            this.IsLoading = false;
        }

    }
}
