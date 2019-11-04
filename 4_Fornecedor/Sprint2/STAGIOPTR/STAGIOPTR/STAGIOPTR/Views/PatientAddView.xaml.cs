using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientAddView : ContentPage
    {
        private PatientAddViewModel _viewModel;
        public PatientAddView()
        {
            InitializeComponent();
            _viewModel = new PatientAddViewModel();
            BindingContext = _viewModel;
        }

        private void PickerGender_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            Picker picker = sender as Picker;
            _viewModel.Patient.Gender =(string) picker.SelectedItem; // This is the model selected in the picker
        }
        
        private void PickerBloodType_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            Picker picker = sender as Picker;
            _viewModel.Patient.BloodType = (string)picker.SelectedItem; // This is the model selected in the picker
        }
    }
}