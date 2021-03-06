﻿using SQLite;

namespace STAGIOPTR.Models
{
    [Table("UserLogged")]
    public class UserLogged
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdUser { get; set; }
        [Ignore]
        public User User { get; set; }
    }
}
