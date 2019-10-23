using SQLite;

namespace STAGIOPTR.Models
{
    [Table("User")]
    public class User
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        [Unique, NotNull]
        public int CPF { get; set; }
        [Unique, NotNull]
        public string Email { get; set; }
        public string Password { get; set; }
        public int AccessLevel { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
    }
}
