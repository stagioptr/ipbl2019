using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientFeedingView : ContentPage
    {
        private readonly PatientFeedingViewModel _viewModel;

        public PatientFeedingView()
        {
            InitializeComponent();
            _viewModel = new PatientFeedingViewModel();
            BindingContext = _viewModel;
        }
    }
}