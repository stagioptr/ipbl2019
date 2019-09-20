using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FoodAddView : ContentPage
    {
        private readonly FoodAddViewModel _viewModel;
        public FoodAddView()
        {
            InitializeComponent();
            _viewModel = new FoodAddViewModel();
            BindingContext = _viewModel;
        }
    }
}