using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Address")]
    public class Address
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        public int CEP { get; set; }
        public string State { get; set; }
        public string Country { get; set; }
        public string City { get; set; }
        public string Neighborhood { get; set; }
        public string Street { get; set; }
        public string Number { get; set; }
        public string Complement { get; set; }
        
    }
}
