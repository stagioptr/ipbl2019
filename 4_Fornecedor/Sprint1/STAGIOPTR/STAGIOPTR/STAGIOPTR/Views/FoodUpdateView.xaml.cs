using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FoodUpdateView : ContentPage
    {
        private readonly FoodUpdateViewModel _viewModel;
        public FoodUpdateView()
        {
            InitializeComponent();
            _viewModel = new FoodUpdateViewModel();
            BindingContext = _viewModel;
        }
    }
}