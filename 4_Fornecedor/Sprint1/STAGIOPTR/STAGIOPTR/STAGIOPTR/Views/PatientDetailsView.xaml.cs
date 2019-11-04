using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientDetailsView : ContentPage
    {
        private readonly PatientDetailsViewModel _viewModel;
        public PatientDetailsView()
        {
            InitializeComponent();
            _viewModel = new PatientDetailsViewModel();
            BindingContext = _viewModel;
        }
    }
}