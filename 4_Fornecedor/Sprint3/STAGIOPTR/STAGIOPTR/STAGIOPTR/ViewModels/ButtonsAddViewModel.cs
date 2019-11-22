using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class ButtonsAddViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private Buttons _buttons;

        public Buttons Buttons
        {
            get { return _buttons; }
            set { SetProperty(ref _buttons, value); }
        }


        public Command LogoutCommand { get; set; }
        public Command ButtonAddCommand { get; set; }

        public ButtonsAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Buttons = new Buttons();
            LogoutCommand = new Command(this.Logout);
            ButtonAddCommand = new Command(ExecuteButtonAddCommand);
        }

        public void ExecuteButtonAddCommand()
        {
            this.Buttons.IdPatient = this.Patient.Id;
            this.Buttons.Patient = this.Patient;
            this.database.InsertButtons(this.Buttons);
            Application.Current.MainPage.Navigation.PopAsync();
        }

    }
}
