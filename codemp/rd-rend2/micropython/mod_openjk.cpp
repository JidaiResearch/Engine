/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2017 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */



#include "server/server.h"

extern "C" {
#include "builtin.h"
#include "runtime.h"
#include "obj.h"
}
#if MICROPY_PY_BUILTINS_FLOAT && MICROPY_PY_MATH





// M_PI is not part of the math.h standard and may not be defined
// And by defining our own we can ensure it uses the correct const format.
#define MP_PI MICROPY_FLOAT_CONST(3.14159265358979323846)

STATIC NORETURN void math_error(void) {
    mp_raise_ValueError("math domain error");
}


#if 0
STATIC mp_obj_t math_generic_1(mp_obj_t x_obj, mp_float_t (*f)(mp_float_t)) {
    mp_float_t x = mp_obj_get_float(x_obj);
    mp_float_t ans = f(x);
    if ((isnan(ans) && !isnan(x)) || (isinf(ans) && !isinf(x))) {
        math_error();
    }
    return mp_obj_new_float(ans);
}

STATIC mp_obj_t math_generic_2(mp_obj_t x_obj, mp_obj_t y_obj, mp_float_t (*f)(mp_float_t, mp_float_t)) {
    mp_float_t x = mp_obj_get_float(x_obj);
    mp_float_t y = mp_obj_get_float(y_obj);
    mp_float_t ans = f(x, y);
    if ((isnan(ans) && !isnan(x) && !isnan(y)) || (isinf(ans) && !isinf(x))) {
        math_error();
    }
    return mp_obj_new_float(ans);
}

#define MATH_FUN_1(py_name, c_name) \
    STATIC mp_obj_t mp_math_ ## py_name(mp_obj_t x_obj) { \
        return math_generic_1(x_obj, MICROPY_FLOAT_C_FUN(c_name)); \
    } \
    STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_## py_name ## _obj, mp_math_ ## py_name);

#define MATH_FUN_1_TO_BOOL(py_name, c_name) \
    STATIC mp_obj_t mp_math_ ## py_name(mp_obj_t x_obj) { return mp_obj_new_bool(c_name(mp_obj_get_float(x_obj))); } \
    STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_## py_name ## _obj, mp_math_ ## py_name);

#define MATH_FUN_1_TO_INT(py_name, c_name) \
    STATIC mp_obj_t mp_math_ ## py_name(mp_obj_t x_obj) { return mp_obj_new_int_from_float(MICROPY_FLOAT_C_FUN(c_name)(mp_obj_get_float(x_obj))); } \
    STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_## py_name ## _obj, mp_math_ ## py_name);

#define MATH_FUN_2(py_name, c_name) \
    STATIC mp_obj_t mp_math_ ## py_name(mp_obj_t x_obj, mp_obj_t y_obj) { \
        return math_generic_2(x_obj, y_obj, MICROPY_FLOAT_C_FUN(c_name)); \
    } \
    STATIC MP_DEFINE_CONST_FUN_OBJ_2(mp_math_## py_name ## _obj, mp_math_ ## py_name);

#define MATH_FUN_2_FLT_INT(py_name, c_name) \
    STATIC mp_obj_t mp_math_ ## py_name(mp_obj_t x_obj, mp_obj_t y_obj) { \
        return mp_obj_new_float(MICROPY_FLOAT_C_FUN(c_name)(mp_obj_get_float(x_obj), mp_obj_get_int(y_obj))); \
    } \
    STATIC MP_DEFINE_CONST_FUN_OBJ_2(mp_math_## py_name ## _obj, mp_math_ ## py_name);

#if MP_NEED_LOG2
#undef log2
#undef log2f
// 1.442695040888963407354163704 is 1/_M_LN2
mp_float_t MICROPY_FLOAT_C_FUN(log2)(mp_float_t x) {
    return MICROPY_FLOAT_C_FUN(log)(x) * MICROPY_FLOAT_CONST(1.442695040888963407354163704);
}
#endif

// sqrt(x): returns the square root of x
MATH_FUN_1(sqrt, sqrt)
// pow(x, y): returns x to the power of y
MATH_FUN_2(pow, pow)
// exp(x)
MATH_FUN_1(exp, exp)
#if MICROPY_PY_MATH_SPECIAL_FUNCTIONS
// expm1(x)
MATH_FUN_1(expm1, expm1)
// log2(x)
MATH_FUN_1(log2, log2)
// log10(x)
MATH_FUN_1(log10, log10)
// cosh(x)
MATH_FUN_1(cosh, cosh)
// sinh(x)
MATH_FUN_1(sinh, sinh)
// tanh(x)
MATH_FUN_1(tanh, tanh)
// acosh(x)
MATH_FUN_1(acosh, acosh)
// asinh(x)
MATH_FUN_1(asinh, asinh)
// atanh(x)
MATH_FUN_1(atanh, atanh)
#endif
// cos(x)
MATH_FUN_1(cos, cos)
// sin(x)
MATH_FUN_1(sin, sin)
// tan(x)
MATH_FUN_1(tan, tan)
// acos(x)
MATH_FUN_1(acos, acos)
// asin(x)
MATH_FUN_1(asin, asin)
// atan(x)
MATH_FUN_1(atan, atan)
// atan2(y, x)
MATH_FUN_2(atan2, atan2)
// ceil(x)
MATH_FUN_1_TO_INT(ceil, ceil)
// copysign(x, y)
STATIC mp_float_t MICROPY_FLOAT_C_FUN(copysign_func)(mp_float_t x, mp_float_t y) {
    return MICROPY_FLOAT_C_FUN(copysign)(x, y);
}
MATH_FUN_2(copysign, copysign_func)
// fabs(x)
STATIC mp_float_t MICROPY_FLOAT_C_FUN(fabs_func)(mp_float_t x) {
    return MICROPY_FLOAT_C_FUN(fabs)(x);
}
MATH_FUN_1(fabs, fabs_func)
// floor(x)
MATH_FUN_1_TO_INT(floor, floor) //TODO: delegate to x.__floor__() if x is not a float
// fmod(x, y)
MATH_FUN_2(fmod, fmod)
// isfinite(x)
MATH_FUN_1_TO_BOOL(isfinite, isfinite)
// isinf(x)
MATH_FUN_1_TO_BOOL(isinf, isinf)
// isnan(x)
MATH_FUN_1_TO_BOOL(isnan, isnan)
// trunc(x)
MATH_FUN_1_TO_INT(trunc, trunc)
// ldexp(x, exp)
MATH_FUN_2_FLT_INT(ldexp, ldexp)
#if MICROPY_PY_MATH_SPECIAL_FUNCTIONS
// erf(x): return the error function of x
MATH_FUN_1(erf, erf)
// erfc(x): return the complementary error function of x
MATH_FUN_1(erfc, erfc)
// gamma(x): return the gamma function of x
MATH_FUN_1(gamma, tgamma)
// lgamma(x): return the natural logarithm of the gamma function of x
MATH_FUN_1(lgamma, lgamma)
#endif
//TODO: factorial, fsum

// Function that takes a variable number of arguments

// log(x[, base])
STATIC mp_obj_t mp_math_log(size_t n_args, const mp_obj_t *args) {
    mp_float_t x = mp_obj_get_float(args[0]);
    if (x <= (mp_float_t)0.0) {
        math_error();
    }
    mp_float_t l = MICROPY_FLOAT_C_FUN(log)(x);
    if (n_args == 1) {
        return mp_obj_new_float(l);
    } else {
        mp_float_t base = mp_obj_get_float(args[1]);
        if (base <= (mp_float_t)0.0) {
            math_error();
        } else if (base == (mp_float_t)1.0) {
            mp_raise_msg(&mp_type_ZeroDivisionError, "division by zero");
        }
        return mp_obj_new_float(l / MICROPY_FLOAT_C_FUN(log)(base));
    }
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_math_log_obj, 1, 2, mp_math_log);

// Functions that return a tuple

// frexp(x): converts a floating-point number to fractional and integral components
STATIC mp_obj_t mp_math_frexp(mp_obj_t x_obj) {
    int int_exponent = 0;
    mp_float_t significand = MICROPY_FLOAT_C_FUN(frexp)(mp_obj_get_float(x_obj), &int_exponent);
    mp_obj_t tuple[2];
    tuple[0] = mp_obj_new_float(significand);
    tuple[1] = mp_obj_new_int(int_exponent);
    return mp_obj_new_tuple(2, tuple);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_frexp_obj, mp_math_frexp);

// modf(x)
STATIC mp_obj_t mp_math_modf(mp_obj_t x_obj) {
    mp_float_t int_part = 0.0;
    mp_float_t fractional_part = MICROPY_FLOAT_C_FUN(modf)(mp_obj_get_float(x_obj), &int_part);
    mp_obj_t tuple[2];
    tuple[0] = mp_obj_new_float(fractional_part);
    tuple[1] = mp_obj_new_float(int_part);
    return mp_obj_new_tuple(2, tuple);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_modf_obj, mp_math_modf);

// Angular conversions

// radians(x)
STATIC mp_obj_t mp_math_radians(mp_obj_t x_obj) {
    return mp_obj_new_float(mp_obj_get_float(x_obj) * (MP_PI / MICROPY_FLOAT_CONST(180.0)));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_radians_obj, mp_math_radians);

// degrees(x)
STATIC mp_obj_t mp_math_degrees(mp_obj_t x_obj) {
    return mp_obj_new_float(mp_obj_get_float(x_obj) * (MICROPY_FLOAT_CONST(180.0) / MP_PI));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mp_math_degrees_obj, mp_math_degrees);


#endif

//#include "../imgui_docks/dock_console.h"
extern "C" int imgui_log(const char *fmt, ...);



//typedef mp_obj_t(*mp_fun_4_t)(mp_obj_t, mp_obj_t, mp_obj_t, mp_obj_t);
//

//
//const mp_obj_type_t mp_type_fun_builtin_4 = {
//	{ &mp_type_type },
//	.name = MP_QSTR_function,
//	.call = fun_builtin_4_call,
//	.unary_op = mp_generic_unary_op,
//};

STATIC mp_obj_t fun_set_velocity(mp_obj_t self_in, size_t n_args, size_t n_kw, const mp_obj_t *args) {
	//assert(MP_OBJ_IS_TYPE(self_in, &mp_type_fun_builtin_3));
	//mp_obj_fun_builtin_fixed_t *self = (mp_obj_fun_builtin_fixed_t *)MP_OBJ_TO_PTR(self_in);
	//mp_arg_check_num(n_args, n_kw, 3, 3, false);

	int playerid = mp_obj_get_int(args[0]);
	float x = mp_obj_get_float(args[1]);
	float y = mp_obj_get_float(args[2]);
	float z = mp_obj_get_float(args[3]);
	imgui_log("Got: %d %f %f %f\n", playerid, x, y, z);

	return mp_obj_new_int(321);
	//return self->fun._3(args[0], args[1], args[2]);
}
const mp_obj_type_t mp_type_fun_setVelocity = {
	&mp_type_type, NULL, MP_QSTR_function, NULL, NULL, fun_set_velocity, mp_generic_unary_op, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};



struct _mp_obj_fun_builtin_fixed_t mp_obj_fun1(const mp_obj_type_t *type_, mp_obj_t fun_) {
	struct _mp_obj_fun_builtin_fixed_t tmp;
	tmp.base.type = type_;
	tmp.fun._1 = (mp_fun_1_t)fun_;
	return tmp;
}
struct _mp_obj_fun_builtin_fixed_t mp_obj_setvelocity(const mp_obj_type_t *type_, mp_obj_t fun_) {
	struct _mp_obj_fun_builtin_fixed_t tmp;
	tmp.base.type = type_;
	tmp.fun._1 = (mp_fun_1_t)fun_;
	return tmp;
}
//struct _mp_obj_fun_builtin_fixed_t mp_obj_fun4(const mp_obj_type_t *type_, mp_obj_t fun_) {
//	struct _mp_obj_fun_builtin_fixed_t tmp;
//	tmp.base.type = type_;
//	tmp.fun._4 = (mp_fun_4_t)fun_;
//	return tmp;
//}

mp_obj_t mp_obj_new_vec3(float *threeFloats) {
	mp_obj_t tuple[3];
	tuple[0] = mp_obj_new_float(threeFloats[0]);
	tuple[1] = mp_obj_new_float(threeFloats[0]);
	tuple[2] = mp_obj_new_float(threeFloats[0]);
	return mp_obj_new_tuple(3, tuple);
}


extern "C" mp_obj_t mp_openjk_getVelocity(mp_obj_t x_obj) {
	//mp_float_t int_part = 0.0;
	//mp_float_t fractional_part = MICROPY_FLOAT_C_FUN(modf)(mp_obj_get_float(x_obj), &int_part);
	mp_obj_t tuple[3];

	int playerid = mp_obj_get_int(x_obj);

	imgui_log("sv.gentities=%p gentsize=%d\n", sv.gentities, sv.gentitySize);

	if (sv.gentities != NULL) { // being in menu, just return (0,0,0)
		float rekt[3] = { 0,0,0 };
		return mp_obj_new_vec3(rekt);
	}

	
	sharedEntity_t *gents = sv.gentities;
	return mp_obj_new_vec3(gents->playerState->velocity);
}

//extern "C" mp_obj_t mp_openjk_setVelocity(mp_obj_t x_obj) {
//	//mp_float_t int_part = 0.0;
//	//mp_float_t fractional_part = MICROPY_FLOAT_C_FUN(modf)(mp_obj_get_float(x_obj), &int_part);
//	//mp_obj_t tuple[2];
//	//tuple[0] = mp_obj_new_float(fractional_part);
//	//tuple[1] = mp_obj_new_float(int_part);
//	//return mp_obj_new_tuple(2, tuple);
//
//	mp_obj_get_tu
//	return NULL;
//}

static const mp_obj_fun_builtin_fixed_t  mp_openjk_getVelocity_obj = mp_obj_fun1(&mp_type_fun_builtin_1, mp_openjk_getVelocity);
//static const mp_obj_fun_builtin_fixed_t  mp_openjk_setVelocity_obj = mp_obj_fun1(&mp_type_fun_builtin_1, mp_openjk_setVelocity);

//STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_math_log_obj, 1, 2, mp_math_log);


typedef struct mp_setvelo_s {
	mp_obj_base_t base;
} mp_setvelo_t;

mp_setvelo_t bla = { &mp_type_fun_setVelocity };

extern "C" const mp_rom_map_elem_t mp_module_openjk_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__    ), MP_ROM_QSTR(MP_QSTR_openjk)             },
    //{ MP_ROM_QSTR(MP_QSTR_e           ), mp_const_float_e                        },
    //{ MP_ROM_QSTR(MP_QSTR_pi          ), mp_const_float_pi                       },
    { MP_ROM_QSTR(MP_QSTR_getVelocity ), MP_ROM_PTR(&mp_openjk_getVelocity_obj ) },
    { MP_ROM_QSTR(MP_QSTR_setVelocity ), MP_ROM_PTR(&bla) },
};


#define MP_DEFINE_CONST_DICT_CPP(dict_name, table_name) \
    const mp_obj_dict_t dict_name = { \
        &mp_type_dict, \
       { \
            1, \
            1, \
            1, \
            MP_ARRAY_SIZE(table_name), \
            MP_ARRAY_SIZE(table_name), \
            (mp_map_elem_t*)(mp_rom_map_elem_t*)table_name \
        }\
    }



STATIC MP_DEFINE_CONST_DICT_CPP(mp_module_openjk_globals, mp_module_openjk_globals_table);

extern "C" const mp_obj_module_t mp_module_openjk = {
     &mp_type_module ,
    (mp_obj_dict_t*)&mp_module_openjk_globals
};

#endif // MICROPY_PY_BUILTINS_FLOAT && MICROPY_PY_MATH
