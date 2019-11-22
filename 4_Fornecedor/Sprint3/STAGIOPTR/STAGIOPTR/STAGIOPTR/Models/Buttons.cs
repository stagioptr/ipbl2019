using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Buttons")]
    public class Buttons
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        public string Type { get; set; }
        [NotNull, Unique]
        public string Title { get; set; }
        public string Number { get; set; }
        public string Email { get; set; }
    }
}
