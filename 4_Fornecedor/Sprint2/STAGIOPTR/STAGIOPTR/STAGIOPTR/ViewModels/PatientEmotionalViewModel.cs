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

        public Command AddEmotionalCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public PatientEmotionalViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Emotional = new ObservableCollection<Emotional>();
            AddEmotionalCommand = new Command(ExecuteAddEmotionalCommand);
            this.LoadAsync();
        }

        private async void ExecuteAddEmotionalCommand()
        {
            await PushAsync<EmotionalAddViewModel>(this.Patient);
        }

        public override async Task LoadAsync()
        {
            var emotionals = await database.getEmotional(this.Patient.Id);
            this.Emotional.Clear();
            foreach (var emotional in emotionals)
            {
                this.Emotional.Add(emotional);
            }
        }

    }
}
