using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FoodDeleteView : ContentPage
    {
        private readonly FoodDeleteViewModel _viewModel;
        public FoodDeleteView()
        {
            InitializeComponent();
            _viewModel = new FoodDeleteViewModel();
            BindingContext = _viewModel;
        }
    }
}