using STAGIOPTR.Views;
using STAGIOPTR.Helpers;
using Xamarin.Forms;

namespace STAGIOPTR
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            SessionControl Session = new SessionControl();
            if(Session.GetSession()==null)
                MainPage = new NavigationPage(new LoginView());
            else
            {
                if(Session.GetSession().AccessLevel == 1)
                    MainPage = new NavigationPage(new MainView());
                else
                    MainPage = new NavigationPage(new PatientView());
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
