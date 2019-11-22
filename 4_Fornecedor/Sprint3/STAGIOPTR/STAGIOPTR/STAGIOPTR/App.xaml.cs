using STAGIOPTR.Views;
using STAGIOPTR.Helpers;
using Xamarin.Forms;
using System;

namespace STAGIOPTR
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            SessionControl Session = new SessionControl();
            int AccessLevel = Session.GetSession();
            switch (AccessLevel)
            {
                case 0:
                    MainPage = new NavigationPage(new LoginView());
                    break;
                case 1:
                    MainPage = new NavigationPage(new MainView());
                    break;
                case 3:
                    MainPage = new NavigationPage(new TabbedPatientView());
                    break;
                case 4:
                    MainPage = new NavigationPage(new PatientView());
                    break;
            }
        }

        protected override void OnStart()
        {
            // Handle when your app starts
        }

        protected override void OnSleep()
        {
            // Handle when your app sleeps
        }

        protected override void OnResume()
        {
            // Handle when your app resumes
        }
    }
}
