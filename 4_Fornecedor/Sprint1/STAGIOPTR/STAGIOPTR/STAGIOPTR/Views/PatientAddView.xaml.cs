using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientAddView : ContentPage
    {
        private readonly PatientAddView _viewModel;
        public PatientAddView()
        {
            InitializeComponent();
            _viewModel = new PatientAddView();
            BindingContext = _viewModel;
        }
    }
}