using STAGIOPTR.Database;
using STAGIOPTR.Models;

namespace STAGIOPTR.Helpers
{
    public class SessionControl
    {
        DatabaseConnection Database = new DatabaseConnection();

        public int GetSession()
        {
            User User = Database.GetLoggedUser();
            return (User == null) ? 0 : User.AccessLevel;
        }
    }
}
