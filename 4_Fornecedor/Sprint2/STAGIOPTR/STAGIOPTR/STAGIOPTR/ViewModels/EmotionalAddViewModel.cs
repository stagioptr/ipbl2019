using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class EmotionalAddViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
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
            this.Emotional.Quality = "Ótimo";
            this.ExecuteAddEmotionalCommand();
        }

        public void ExecuteSatisfiedCommand()
        {
            this.Emotional.Quality = "Bom";
            this.ExecuteAddEmotionalCommand();
        }

        public void ExecuteNormalCommand()
        {
            this.Emotional.Quality = "Regular";
            this.ExecuteAddEmotionalCommand();
        }

        public void ExecuteDissatisfiedCommand()
        {
            this.Emotional.Quality = "Ruim";
            this.ExecuteAddEmotionalCommand();
        }

        public void ExecuteVeryDissatisfiedCommand()
        {
            this.Emotional.Quality = "Péssimo";
            this.ExecuteAddEmotionalCommand();
        }

    }
}
