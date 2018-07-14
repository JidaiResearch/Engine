
Number.prototype.add    = function(other) { return this  + other; } // eleven          = one  + ten;
Number.prototype.eq     = function(other) { return this == other; } // tenEqualsTen    = ten == ten;
Number.prototype.neq    = function(other) { return this != other; } // tenNotEqualsTen = ten != ten;
Number.prototype.neg    = function(     ) { return         -this; } // minusOne        =      - one;
Number.prototype.self   = function(     ) { return  Number(this); } // selfOne         =      + one;
