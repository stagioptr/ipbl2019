using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Globalization;
using STAGIOPTR.MongoModels;
using Xamarin.Forms;
using STAGIOPTR.Helpers;

namespace STAGIOPTR.ViewModels
{
    public class EmotionalAddViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        MongoDatabase mongo = new MongoDatabase();

        private Patient _patient;
        public Command LogoutCommand { get; set; }
        public Command VerySatisfiedCommand { get; }
        public Command SatisfiedCommand { get; }
        public Command NormalCommand { get; }
        public Command DissatisfiedCommand { get; }
        public Command VeryDissatisfiedCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private Emotional emotional;

        public Emotional Emotional
        {
            get { return emotional; }
            set { SetProperty(ref emotional, value); }
        }

        private TimeSpan _emotionalTime;

        public TimeSpan EmotionalTime
        {
            get { return _emotionalTime; }
            set { SetProperty(ref _emotionalTime, value); }
        }

        public EmotionalAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Emotional = new Emotional();
            this.Emotional.EmotionalTime = DateTime.Now;
            this.EmotionalTime = DateTime.Now.TimeOfDay;
            LogoutCommand = new Command(this.Logout);
            VerySatisfiedCommand = new Command(ExecuteVerySatisfiedCommand);
            SatisfiedCommand = new Command(ExecuteSatisfiedCommand);
            NormalCommand = new Command(ExecuteNormalCommand);
            DissatisfiedCommand = new Command(ExecuteDissatisfiedCommand);
            VeryDissatisfiedCommand = new Command(ExecuteVeryDissatisfiedCommand);
        }

        public void ExecuteAddEmotionalCommand()
        {
            this.Emotional.EmotionalTime = this.Emotional.EmotionalTime.Add(this.EmotionalTime);
            this.Emotional.IdPatient = this.Patient.Id;
            this.database.InsertEmotional(this.Emotional);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

        public void ExecuteVerySatisfiedCommand()
        {
            this.Emotional.Quality = 5;
            this.ExecuteAddEmotionalCommand();
            this.SendMongo();
        }

        public void ExecuteSatisfiedCommand()
        {
            this.Emotional.Quality = 4;
            this.ExecuteAddEmotionalCommand();
            this.SendMongo();
        }

        public void ExecuteNormalCommand()
        {
            this.Emotional.Quality = 3;
            this.ExecuteAddEmotionalCommand();
            this.SendMongo();
        }

        public void ExecuteDissatisfiedCommand()
        {
            this.Emotional.Quality = 2;
            this.ExecuteAddEmotionalCommand();
            this.SendMongo();
        }

        public void ExecuteVeryDissatisfiedCommand()
        {
            this.Emotional.Quality = 1;
            this.ExecuteAddEmotionalCommand();
            this.SendMongo();
        }

        private async void SendMongo()
        {
            Coordinates Coordinates = await Location.GetLocation();
            EmotionalTopic emotional = new EmotionalTopic()
            {
                IdPatient = this.Patient.CPF,
                DataHora = this.Emotional.EmotionalTime,
                Quality = this.Emotional.Quality,
                Latitude = Coordinates.Latitude,
                Longitude = Coordinates.Longitude,
                Altitude = Coordinates.Altitude
            };
            mongo.InsertEmotional(emotional);
        }

    }
}
