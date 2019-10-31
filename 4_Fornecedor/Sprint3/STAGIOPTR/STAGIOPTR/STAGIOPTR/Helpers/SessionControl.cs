using STAGIOPTR.Database;
using STAGIOPTR.Models;

namespace STAGIOPTR.Helpers
{
    public class SessionControl
    {
        DatabaseConnection Database = new DatabaseConnection();

        public User GetSession()
        {
            return Database.GetLoggedUser();
        }
    }
}
