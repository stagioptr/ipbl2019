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
    public class SleepAddViewModel : BaseViewModel
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

        private Sleep _sleep;

        public Sleep Sleep
        {
            get { return _sleep; }
            set { SetProperty(ref _sleep, value); }
        }

        private TimeSpan _sleepTime;    

        public TimeSpan SleepTime
        {
            get { return _sleepTime; }
            set { _sleepTime = value; }
        }


        public SleepAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Sleep = new Sleep();
            this.Sleep.SleepTime = DateTime.Now;
            this.SleepTime = DateTime.Now.TimeOfDay;
            LogoutCommand = new Command(this.Logout);
            VerySatisfiedCommand = new Command(ExecuteVerySatisfiedCommand);
            SatisfiedCommand = new Command(ExecuteSatisfiedCommand);
            NormalCommand = new Command(ExecuteNormalCommand);
            DissatisfiedCommand = new Command(ExecuteDissatisfiedCommand);
            VeryDissatisfiedCommand = new Command(ExecuteVeryDissatisfiedCommand);
        }

        public void ExecuteAddSleepCommand()
        {
            this.Sleep.SleepTime = this.Sleep.SleepTime.Add(this.SleepTime);
            this.Sleep.IdPatient = this.Patient.Id;
            this.database.InsertSleep(this.Sleep);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

        public void ExecuteVerySatisfiedCommand()
        {
            this.Sleep.Quality = 5;
            this.ExecuteAddSleepCommand();
            this.SendMongo();
        }

        public void ExecuteSatisfiedCommand()
        {
            this.Sleep.Quality = 4;
            this.ExecuteAddSleepCommand();
            this.SendMongo();
        }

        public void ExecuteNormalCommand()
        {
            this.Sleep.Quality = 3;
            this.ExecuteAddSleepCommand();
            this.SendMongo();
        }

        public void ExecuteDissatisfiedCommand()
        {
            this.Sleep.Quality = 2;
            this.ExecuteAddSleepCommand();
            this.SendMongo();
        }

        public void ExecuteVeryDissatisfiedCommand()
        {
            this.Sleep.Quality = 1;
            this.ExecuteAddSleepCommand();
            this.SendMongo();
        }

        private async void SendMongo()
        {
            Coordinates Coordinates = await Location.GetLocation();
            SleepTopic sleep = new SleepTopic()
            {
                IdPatient = this.Patient.CPF,
                DataHora = this.Sleep.SleepTime,
                Quality = this.Sleep.Quality,
                Duration = this.Sleep.Duration,
                Latitude = Coordinates.Latitude,
                Longitude = Coordinates.Longitude,
                Altitude = Coordinates.Altitude
            };
            mongo.InsertSleep(sleep);
        }
    }
}
