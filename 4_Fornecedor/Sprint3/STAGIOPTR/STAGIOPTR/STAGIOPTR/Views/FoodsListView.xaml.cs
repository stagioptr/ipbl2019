using STAGIOPTR.ViewModels;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using STAGIOPTR.Models;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FoodsListView : ContentPage
    {
        private readonly FoodsListViewModel _viewModel;

        public FoodsListView()
        {
            InitializeComponent();
            _viewModel = new FoodsListViewModel();
            BindingContext = _viewModel;
        }

        private void ListView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null)
            {
                _viewModel.ShowUpdateFoodCommand.Execute(e.SelectedItem);
            }
        }

        protected override void OnAppearing()
        {
            _ = this._viewModel.LoadAsync();
        }

        public void DeleteAction(object sender, EventArgs e)
        {
            var menuItem = sender as MenuItem;
            Food food = menuItem.CommandParameter as Food;
            _viewModel.DeleteFoodCommand(food);
        }
    }
}