using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class LoginView : ContentPage
    {
        private LoginViewModel _viewModel;

        public LoginView()
        {
            InitializeComponent();
            _viewModel = new LoginViewModel();
            BindingContext = _viewModel;
        }
    }
}