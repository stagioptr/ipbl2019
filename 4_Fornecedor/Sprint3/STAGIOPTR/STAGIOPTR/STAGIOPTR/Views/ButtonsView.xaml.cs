using STAGIOPTR.Models;
using STAGIOPTR.ViewModels;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ButtonsView : ContentPage
    {
        private readonly ButtonsViewModel _viewModel;

        public ButtonsView()
        {
            InitializeComponent();
            _viewModel = new ButtonsViewModel();
            BindingContext = _viewModel;
        }

        private void ListView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null)
            {
                _viewModel.CallCommand.Execute(e.SelectedItem);
                ((ListView)sender).SelectedItem = null;
            }
        }

        public void DeleteAction(object sender, EventArgs e)
        {
            var menuItem = sender as MenuItem;
            Buttons Button = menuItem.CommandParameter as Buttons;
            _viewModel.DeleteButtonCommand(Button);
        }

        protected override void OnAppearing()
        {
            _ = this._viewModel.LoadAsync();
        }
    }
}