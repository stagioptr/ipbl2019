using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class SignupView : ContentPage
    {
        private readonly SignupViewModel _viewModel;
        public SignupView()
        {
            InitializeComponent();
            _viewModel = new SignupViewModel();
            BindingContext = _viewModel;
        }
    }
}