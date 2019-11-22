using Plugin.Messaging;
using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;
using STAGIOPTR.MongoModels;
using STAGIOPTR.Helpers;

namespace STAGIOPTR.ViewModels
{
    public class ButtonsViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        MongoDatabase mongo = new MongoDatabase();

        private ObservableCollection<Buttons> _buttons;

        public ObservableCollection<Buttons> Buttons
        {
            get { return _buttons; }
            set { SetProperty(ref _buttons, value); }
        }

        public Command LoadButtonsCommand { get; }
        public Command LogoutCommand { get; }
        public Command AddButtonCommand { get; }
        public Command<Buttons> CallCommand { get; }
        public Command EmergencyCommand { get; }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public Patient Patient { get; }

        public ButtonsViewModel()
        {
            User User = database.GetLoggedUser();
            this.Patient = database.GetPatientPerId(User.IdPatient);
            Buttons = new ObservableCollection<Buttons>();
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddButtonCommand = new Command(ExecuteAddButtonCommand);
            LoadButtonsCommand = new Command(LoadAsyncList);
            LogoutCommand = new Command(this.Logout);
            CallCommand = new Command<Buttons>(ExecuteCallCommand);
            EmergencyCommand = new Command(ExecuteEmergencyCommand);
        }

        private async void ExecuteAddButtonCommand()
        {
            await PushAsync<ButtonsAddViewModel>(this.Patient);
        }

        private async void ExecuteCallCommand(Buttons Buttons)
        {
            var phoneDialer = CrossMessaging.Current.PhoneDialer;
            if (phoneDialer.CanMakePhoneCall && !String.IsNullOrWhiteSpace(Buttons.Number.ToString()))
                phoneDialer.MakePhoneCall(Buttons.Number.ToString());
        }

        private async void ExecuteEmergencyCommand()
        {
            Coordinates Coordinates = await Location.GetLocation();
            EmergencyTopic emergency = new EmergencyTopic()
            {
                IdPatient = this.Patient.CPF,
                DataHora = DateTime.Now,
                Latitude = Coordinates.Latitude,
                Longitude = Coordinates.Longitude,
                Altitude = Coordinates.Altitude,
            };
            mongo.InsertEmergency(emergency);
            var phoneDialer = CrossMessaging.Current.PhoneDialer;
            if (phoneDialer.CanMakePhoneCall && !String.IsNullOrWhiteSpace(this.Patient.EmergencyPhone.ToString()))
                phoneDialer.MakePhoneCall(Patient.EmergencyPhone.ToString());
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var buttons = database.ListButtons(this.Patient.Id);
            this.Buttons.Clear();
            foreach (var button in buttons)
            {
                this.Buttons.Add(button);
                Console.WriteLine(this.Buttons.Count);
            }
            this.IsLoading = false;
        }

        public void DeleteButtonCommand(Buttons Buttons)
        {
            this.database.DeleteButtons(Buttons);
            this.Buttons.Remove(Buttons);
        }

    }
}
