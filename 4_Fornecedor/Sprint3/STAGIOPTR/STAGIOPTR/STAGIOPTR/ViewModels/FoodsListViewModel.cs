using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FoodsListViewModel : BaseViewModel
    {
        private ObservableCollection<Food> _foods;
        DatabaseConnection database = new DatabaseConnection();

        public Command AddFoodCommand { get; }

        public Command<Food> ShowUpdateFoodCommand { get; }

        public Command LoadFoodsCommand { get; }

        public ObservableCollection<Food> Foods
        {
            get { return _foods; }
            set { SetProperty(ref _foods, value); }
        }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public FoodsListViewModel()
        {
            Foods = new ObservableCollection<Food>();
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddFoodCommand = new Command(ExecuteAddFoodCommand);
            ShowUpdateFoodCommand = new Command<Food>(ExecuteShowUpdateFoodCommand);
            LoadFoodsCommand = new Command(LoadAsyncList);

        }

        private async void ExecuteShowUpdateFoodCommand(Food food)
        {
            await PushAsync<FoodUpdateViewModel>(food);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var foods = await database.ListFood();
            this.Foods.Clear();
            foreach (var food in foods)
            {
                this.Foods.Add(food);
            }
            this.IsLoading = false;
        }

        private async void ExecuteAddFoodCommand()
        {
            await PushAsync<FoodAddViewModel>();
        }

        public void DeleteFoodCommand(Food Food)
        {
            this.database.DeleteFood(Food);
            this.Foods.Remove(Food);
        }

    }
}
