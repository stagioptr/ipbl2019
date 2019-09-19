using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using System;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientsListView : ContentPage
    {
        private readonly PatientsListViewModel _viewModel;
        public PatientsListView()
        {
            InitializeComponent();
            _viewModel = new PatientsListViewModel();
            BindingContext = _viewModel;
        }
        private async void Button_Clicked(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new SOSButtonView());
        }
        private void ListView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if(e.SelectedItem != null)
            {
                
            }
        }
    }
}