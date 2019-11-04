using STAGIOPTR.Database;
using STAGIOPTR.Models;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FoodUpdateViewModel : BaseViewModel
    {
        private Food _food;

        public Food Food
        {
            get { return _food; }
            set { SetProperty(ref _food, value); }
        }

        DatabaseConnection database = new DatabaseConnection();
        public Command LogoutCommand { get; set; }
        public Command UpdateFoodCommand { get; }

        public FoodUpdateViewModel()
        {

        }

        public FoodUpdateViewModel(Food Food)
        {
            this.Food = Food;
            LogoutCommand = new Command(this.Logout);
            UpdateFoodCommand = new Command(ExecuteUpdateFoodCommand);
        }

        public void ExecuteUpdateFoodCommand()
        {
            this.database.UpdateFood(this.Food);
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}

