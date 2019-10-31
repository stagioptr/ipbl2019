using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Food")]
    public class Food
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Unique]
        public string Name { get; set; }

    }
}
