using STAGIOPTR.Models;
using STAGIOPTR.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientDrugsView : ContentPage
    {
        private readonly PatientDrugsViewModel _viewModel;

        public PatientDrugsView()
        {
            InitializeComponent();
            _viewModel = new PatientDrugsViewModel();
            BindingContext = _viewModel;
        }

        public void DeleteAction(object sender, EventArgs e)
        {
            var menuItem = sender as MenuItem;
            Drugs Drugs = menuItem.CommandParameter as Drugs;
            _viewModel.DeleteDrugsCommand(Drugs);
        }

        private void ListView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null)
            {
                _viewModel.ShowDrugsCommand.Execute(e.SelectedItem);
            }
            ((ListView)sender).SelectedItem = null;
        }
        protected override void OnAppearing()
        {
            _ = this._viewModel.LoadAsync();
        }
    }
}