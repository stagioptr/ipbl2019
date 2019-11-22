using STAGIOPTR.Database;
using STAGIOPTR.Helpers;
using STAGIOPTR.Models;
using STAGIOPTR.MongoModels;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FeedingAddFoodTimeViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        MongoDatabase mongo = new MongoDatabase();

        private Feeding _feeding;

        public Feeding Feeding
        {
            get { return _feeding; }
            set { _feeding = value; }
        }

        private string _patientName;

        public string PatientName
        {
            get { return _patientName; }
            set { SetProperty(ref _patientName, value); }
        }

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public Command LogoutCommand { get; set; }
        public Command FeedingAddCommand { get; }

        public FeedingAddFoodTimeViewModel(Feeding Feeding)
        {
            this.Feeding = Feeding;
            this.Patient = database.GetPatientPerId(Feeding.IdPatient);
            PatientName = this.Patient.Name;
            LogoutCommand = new Command(this.Logout);
            FeedingAddCommand = new Command(ExecuteFeedingAddCommand);
        }

        public void ExecuteFeedingAddCommand()
        {
            this.database.InsertFeeding(this.Feeding);
            this.SendMongo();
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

        private async void SendMongo()
        {
            Coordinates Coordinates = await Location.GetLocation();
            FeedingTopic feeding = new FeedingTopic()
            {
                IdPatient = this.Patient.CPF,
                DataHora = DateTime.Now,
                Food = this.Feeding.Food,
                Qtd = this.Feeding.qtd,
                Latitude = Coordinates.Latitude,
                Longitude = Coordinates.Longitude,
                Altitude = Coordinates.Altitude
            };
            mongo.InsertFeeding(feeding);
        }

    }
}
