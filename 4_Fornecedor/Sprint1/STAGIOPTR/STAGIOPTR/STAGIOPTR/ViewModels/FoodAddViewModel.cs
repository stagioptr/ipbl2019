using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FoodAddViewModel:BaseViewModel
    {
        private Food _food;
        DatabaseConnection database = new DatabaseConnection();
        public Command AddFoodCommand { get; }

        public Food Food
        {
            get { return _food; }
            set { SetProperty(ref _food, value); }
        }

        public FoodAddViewModel()
        {
            Food = new Food();
            AddFoodCommand = new Command(ExecuteAddFoodCommand);
        }

        public void ExecuteAddFoodCommand()
        {
            this.database.InsertFood(this.Food);
            Application.Current.MainPage.Navigation.PopAsync();
        }

    }
}
