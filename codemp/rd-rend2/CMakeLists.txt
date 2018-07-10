# Make sure the user is not executing this script directly
if(NOT InOpenJK)
	message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT InOpenJK)

set(MPRend2IncludeDirectories
	"${SharedDir}"
	"${MPDir}"
	"${MPDir}/rd-rend2"
	"${GSLIncludeDirectory}"
	)

set(MPRend2Files
	"${MPDir}/rd-rend2/iqm.h"
	"${MPDir}/rd-rend2/glext.h"
	"${MPDir}/rd-rend2/qgl.h"
	"${MPDir}/rd-rend2/G2_API.cpp"
	"${MPDir}/rd-rend2/G2_bolts.cpp"
	"${MPDir}/rd-rend2/G2_bones.cpp"
	"${MPDir}/rd-rend2/G2_misc.cpp"
	"${MPDir}/rd-rend2/G2_surfaces.cpp"
	"${MPDir}/rd-rend2/tr_allocator.cpp"
	"${MPDir}/rd-rend2/tr_allocator.h"
	"${MPDir}/rd-rend2/tr_animation.cpp"
	"${MPDir}/rd-rend2/tr_backend.cpp"
	"${MPDir}/rd-rend2/tr_bsp.cpp"
	"${MPDir}/rd-rend2/tr_cache.cpp"
	"${MPDir}/rd-rend2/tr_cache.h"
	"${MPDir}/rd-rend2/tr_cmds.cpp"
	"${MPDir}/rd-rend2/tr_compose_models.cpp"
	"${MPDir}/rd-rend2/tr_compose_models.h"
	"${MPDir}/rd-rend2/tr_curve.cpp"
	"${MPDir}/rd-rend2/tr_decals.cpp"
	"${MPDir}/rd-rend2/tr_extensions.cpp"
	"${MPDir}/rd-rend2/tr_extramath.cpp"
	"${MPDir}/rd-rend2/tr_extramath.h"
	"${MPDir}/rd-rend2/tr_extratypes.h"
	"${MPDir}/rd-rend2/tr_fbo.cpp"
	"${MPDir}/rd-rend2/tr_fbo.h"
	"${MPDir}/rd-rend2/tr_flares.cpp"
	"${MPDir}/rd-rend2/tr_ghoul2.cpp"
	"${MPDir}/rd-rend2/tr_glsl.cpp"
	"${MPDir}/rd-rend2/tr_glsl_parse.cpp"
	"${MPDir}/rd-rend2/tr_image.cpp"
	"${MPDir}/rd-rend2/tr_imgui.cpp"
	"${MPDir}/rd-rend2/tr_init.cpp"
	"${MPDir}/rd-rend2/tr_light.cpp"
	"${MPDir}/rd-rend2/tr_local.h"
	"${MPDir}/rd-rend2/tr_main.cpp"
	"${MPDir}/rd-rend2/tr_marks.cpp"
	"${MPDir}/rd-rend2/tr_mesh.cpp"
	"${MPDir}/rd-rend2/tr_model.cpp"
	"${MPDir}/rd-rend2/tr_model_iqm.cpp"
	"${MPDir}/rd-rend2/tr_postprocess.cpp"
	"${MPDir}/rd-rend2/tr_postprocess.h"
	"${MPDir}/rd-rend2/tr_scene.cpp"
	"${MPDir}/rd-rend2/tr_shade.cpp"
	"${MPDir}/rd-rend2/tr_shade_calc.cpp"
	"${MPDir}/rd-rend2/tr_shader.cpp"
	"${MPDir}/rd-rend2/tr_shadows.cpp"
	"${MPDir}/rd-rend2/tr_skin.cpp"
	"${MPDir}/rd-rend2/tr_sky.cpp"
	"${MPDir}/rd-rend2/tr_subs.cpp"
	"${MPDir}/rd-rend2/tr_surface.cpp"
	"${MPDir}/rd-rend2/tr_vbo.cpp"
	"${MPDir}/rd-rend2/tr_world.cpp"
	"${MPDir}/rd-rend2/tr_weather.cpp"
	"${MPDir}/rd-rend2/tr_weather.h"
	)
source_group("renderer" FILES ${MPRend2Files})

file(GLOB MPRend2GLSLFiles "${MPDir}/rd-rend2/glsl/*.glsl")
source_group("renderer\\glsl" FILES ${MPRend2GLSLFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2GLSLFiles})

set(MPRend2Ghoul2Files
	"${MPDir}/ghoul2/g2_local.h"
	"${MPDir}/ghoul2/ghoul2_shared.h"
	"${MPDir}/ghoul2/G2_gore.cpp"
	"${MPDir}/ghoul2/G2_gore.h")
source_group("ghoul2" FILES ${MPRend2Ghoul2Files})
set(MPRend2Files ${MPRend2Files} ${MPRend2Ghoul2Files})


set(MPRend2ImGuiFiles
	"${MPDir}/rd-rend2/ccall.h"
	"${MPDir}/rd-rend2/imgui/ffi.cpp"
	"${MPDir}/rd-rend2/imgui/imconfig.h"
	"${MPDir}/rd-rend2/imgui/imgui.cpp"
	"${MPDir}/rd-rend2/imgui/imgui.h"
	"${MPDir}/rd-rend2/imgui/imgui_api.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_api.h"
	"${MPDir}/rd-rend2/imgui/imgui_c_utils.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_c_utils.h"
	"${MPDir}/rd-rend2/imgui/imgui_default_docks.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_default_docks.h"
	"${MPDir}/rd-rend2/imgui/imgui_demo.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_dock.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_dock.h"
	"${MPDir}/rd-rend2/imgui/imgui_draw.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_fixedarea.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_fixedarea.h"
	"${MPDir}/rd-rend2/imgui/imgui_impl_idtech3_gles.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_impl_idtech3_gles.h"
	"${MPDir}/rd-rend2/imgui/imgui_internal.h"
	"${MPDir}/rd-rend2/imgui/imgui_utils.cpp"
	"${MPDir}/rd-rend2/imgui/imgui_utils.h"
	"${MPDir}/rd-rend2/imgui/include_imgui.h"
	"${MPDir}/rd-rend2/imgui/include_quakegl.h"
	"${MPDir}/rd-rend2/imgui/stb_rect_pack.h"
	"${MPDir}/rd-rend2/imgui/stb_textedit.h"
	"${MPDir}/rd-rend2/imgui/stb_truetype.h"
)
source_group("imgui" FILES ${MPRend2ImGuiFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2ImGuiFiles})

set(MPRend2ImGuiDockFiles
	"${MPDir}/rd-rend2/imgui_docks/dock.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_console.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_console.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_julia.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_julia.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_micropython.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_micropython.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_node.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_node.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_repl.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_repl.h"
	"${MPDir}/rd-rend2/imgui_docks/dock_skeleton.cpp"
	"${MPDir}/rd-rend2/imgui_docks/dock_skeleton.h"
)
source_group("imgui_dock" FILES ${MPRend2ImGuiDockFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2ImGuiDockFiles})

set(MPRend2ImGuiOpenJKFiles
	"${MPDir}/rd-rend2/imgui_openjk/imgui_openjk_default_docks.h"
	"${MPDir}/rd-rend2/imgui_openjk/imgui_openjk_default_docks.cpp"
	"${MPDir}/rd-rend2/imgui_openjk/gluecode.h"
	"${MPDir}/rd-rend2/imgui_openjk/gluecode.cpp"
)
source_group("imgui_openjk" FILES ${MPRend2ImGuiOpenJKFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2ImGuiOpenJKFiles})

set(MPRend2ImGuiDocksOpenJKFiles
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_all.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_all.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_controlflow.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_controlflow.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_images.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_images.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mapinfo.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mapinfo.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mdxa.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mdxa.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mdxm.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_mdxm.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_models.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_models.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_opsys.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_opsys.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_perf.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_perf.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_quakeshaders.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_quakeshaders.h"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_shadereditor.cpp"
	"${MPDir}/rd-rend2/imgui_docks_openjk/dock_shadereditor.h"
)
source_group("imgui_docks_openjk" FILES ${MPRend2ImGuiDocksOpenJKFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2ImGuiDocksOpenJKFiles})

set(MPRend2MicroPython
	"${MPDir}/rd-rend2/micropython/argcheck.c"
	"${MPDir}/rd-rend2/micropython/asmarm.c"
	"${MPDir}/rd-rend2/micropython/asmarm.h"
	"${MPDir}/rd-rend2/micropython/asmbase.c"
	"${MPDir}/rd-rend2/micropython/asmbase.h"
	"${MPDir}/rd-rend2/micropython/asmthumb.c"
	"${MPDir}/rd-rend2/micropython/asmthumb.h"
	"${MPDir}/rd-rend2/micropython/asmx64.c"
	"${MPDir}/rd-rend2/micropython/asmx64.h"
	"${MPDir}/rd-rend2/micropython/asmx86.c"
	"${MPDir}/rd-rend2/micropython/asmx86.h"
	"${MPDir}/rd-rend2/micropython/asmxtensa.c"
	"${MPDir}/rd-rend2/micropython/asmxtensa.h"
	"${MPDir}/rd-rend2/micropython/bc.c"
	"${MPDir}/rd-rend2/micropython/bc.h"
	"${MPDir}/rd-rend2/micropython/bc0.h"
	"${MPDir}/rd-rend2/micropython/binary.c"
	"${MPDir}/rd-rend2/micropython/binary.h"
	"${MPDir}/rd-rend2/micropython/builtin.h"
	"${MPDir}/rd-rend2/micropython/builtinevex.c"
	"${MPDir}/rd-rend2/micropython/builtinhelp.c"
	"${MPDir}/rd-rend2/micropython/builtinimport.c"
	"${MPDir}/rd-rend2/micropython/compile.c"
	"${MPDir}/rd-rend2/micropython/compile.h"
	"${MPDir}/rd-rend2/micropython/emit.h"
	"${MPDir}/rd-rend2/micropython/emitbc.c"
	"${MPDir}/rd-rend2/micropython/emitcommon.c"
	"${MPDir}/rd-rend2/micropython/emitglue.c"
	"${MPDir}/rd-rend2/micropython/emitglue.h"
	"${MPDir}/rd-rend2/micropython/emitinlinethumb.c"
	"${MPDir}/rd-rend2/micropython/emitinlinextensa.c"
	"${MPDir}/rd-rend2/micropython/emitnarm.c"
	"${MPDir}/rd-rend2/micropython/emitnative.c"
	"${MPDir}/rd-rend2/micropython/emitnthumb.c"
	"${MPDir}/rd-rend2/micropython/emitnx64.c"
	"${MPDir}/rd-rend2/micropython/emitnx86.c"
	"${MPDir}/rd-rend2/micropython/emitnxtensa.c"
	"${MPDir}/rd-rend2/micropython/formatfloat.c"
	"${MPDir}/rd-rend2/micropython/formatfloat.h"
	"${MPDir}/rd-rend2/micropython/frozenmod.c"
	"${MPDir}/rd-rend2/micropython/frozenmod.h"
	"${MPDir}/rd-rend2/micropython/gc.c"
	"${MPDir}/rd-rend2/micropython/gc.h"
	"${MPDir}/rd-rend2/micropython/grammar.h"
	"${MPDir}/rd-rend2/micropython/lexer.c"
	"${MPDir}/rd-rend2/micropython/lexer.h"
	"${MPDir}/rd-rend2/micropython/malloc.c"
	"${MPDir}/rd-rend2/micropython/map.c"
	"${MPDir}/rd-rend2/micropython/misc.h"
	"${MPDir}/rd-rend2/micropython/modarray.c"
	"${MPDir}/rd-rend2/micropython/modbuiltins.c"
	"${MPDir}/rd-rend2/micropython/modcmath.c"
	"${MPDir}/rd-rend2/micropython/modcollections.c"
	"${MPDir}/rd-rend2/micropython/modgc.c"
	"${MPDir}/rd-rend2/micropython/modio.c"
	"${MPDir}/rd-rend2/micropython/modmath.c"
	"${MPDir}/rd-rend2/micropython/modmicropython.c"
	"${MPDir}/rd-rend2/micropython/modstruct.c"
	"${MPDir}/rd-rend2/micropython/modsys.c"
	"${MPDir}/rd-rend2/micropython/modthread.c"
	"${MPDir}/rd-rend2/micropython/moduerrno.c"
	"${MPDir}/rd-rend2/micropython/mpconfig.h"
	"${MPDir}/rd-rend2/micropython/mpconfigport.h"
	"${MPDir}/rd-rend2/micropython/mperrno.h"
	"${MPDir}/rd-rend2/micropython/mphal.h"
	"${MPDir}/rd-rend2/micropython/mpprint.c"
	"${MPDir}/rd-rend2/micropython/mpprint.h"
	"${MPDir}/rd-rend2/micropython/mpstate.c"
	"${MPDir}/rd-rend2/micropython/mpstate.h"
	"${MPDir}/rd-rend2/micropython/mpthread.h"
	"${MPDir}/rd-rend2/micropython/mpz.c"
	"${MPDir}/rd-rend2/micropython/mpz.h"
	"${MPDir}/rd-rend2/micropython/mp_lib_utils_printf.c"
	"${MPDir}/rd-rend2/micropython/nativeglue.c"
	"${MPDir}/rd-rend2/micropython/nlr.c"
	"${MPDir}/rd-rend2/micropython/nlr.h"
	"${MPDir}/rd-rend2/micropython/nlrsetjmp.c"
	"${MPDir}/rd-rend2/micropython/nlrthumb.c"
	"${MPDir}/rd-rend2/micropython/nlrx64.c"
	"${MPDir}/rd-rend2/micropython/nlrx86.c"
	"${MPDir}/rd-rend2/micropython/nlrxtensa.c"
	"${MPDir}/rd-rend2/micropython/obj.c"
	"${MPDir}/rd-rend2/micropython/obj.h"
	"${MPDir}/rd-rend2/micropython/objarray.c"
	"${MPDir}/rd-rend2/micropython/objarray.h"
	"${MPDir}/rd-rend2/micropython/objattrtuple.c"
	"${MPDir}/rd-rend2/micropython/objbool.c"
	"${MPDir}/rd-rend2/micropython/objboundmeth.c"
	"${MPDir}/rd-rend2/micropython/objcell.c"
	"${MPDir}/rd-rend2/micropython/objclosure.c"
	"${MPDir}/rd-rend2/micropython/objcomplex.c"
	"${MPDir}/rd-rend2/micropython/objdeque.c"
	"${MPDir}/rd-rend2/micropython/objdict.c"
	"${MPDir}/rd-rend2/micropython/objenumerate.c"
	"${MPDir}/rd-rend2/micropython/objexcept.c"
	"${MPDir}/rd-rend2/micropython/objexcept.h"
	"${MPDir}/rd-rend2/micropython/objfilter.c"
	"${MPDir}/rd-rend2/micropython/objfloat.c"
	"${MPDir}/rd-rend2/micropython/objfun.c"
	"${MPDir}/rd-rend2/micropython/objfun.h"
	"${MPDir}/rd-rend2/micropython/objgenerator.c"
	"${MPDir}/rd-rend2/micropython/objgenerator.h"
	"${MPDir}/rd-rend2/micropython/objgetitemiter.c"
	"${MPDir}/rd-rend2/micropython/objint.c"
	"${MPDir}/rd-rend2/micropython/objint.h"
	"${MPDir}/rd-rend2/micropython/objint_longlong.c"
	"${MPDir}/rd-rend2/micropython/objint_mpz.c"
	"${MPDir}/rd-rend2/micropython/objlist.c"
	"${MPDir}/rd-rend2/micropython/objlist.h"
	"${MPDir}/rd-rend2/micropython/objmap.c"
	"${MPDir}/rd-rend2/micropython/objmodule.c"
	"${MPDir}/rd-rend2/micropython/objmodule.h"
	"${MPDir}/rd-rend2/micropython/objnamedtuple.c"
	"${MPDir}/rd-rend2/micropython/objnamedtuple.h"
	"${MPDir}/rd-rend2/micropython/objnone.c"
	"${MPDir}/rd-rend2/micropython/objobject.c"
	"${MPDir}/rd-rend2/micropython/objpolyiter.c"
	"${MPDir}/rd-rend2/micropython/objproperty.c"
	"${MPDir}/rd-rend2/micropython/objrange.c"
	"${MPDir}/rd-rend2/micropython/objreversed.c"
	"${MPDir}/rd-rend2/micropython/objset.c"
	"${MPDir}/rd-rend2/micropython/objsingleton.c"
	"${MPDir}/rd-rend2/micropython/objslice.c"
	"${MPDir}/rd-rend2/micropython/objstr.c"
	"${MPDir}/rd-rend2/micropython/objstr.h"
	"${MPDir}/rd-rend2/micropython/objstringio.c"
	"${MPDir}/rd-rend2/micropython/objstringio.h"
	"${MPDir}/rd-rend2/micropython/objstrunicode.c"
	"${MPDir}/rd-rend2/micropython/objtuple.c"
	"${MPDir}/rd-rend2/micropython/objtuple.h"
	"${MPDir}/rd-rend2/micropython/objtype.c"
	"${MPDir}/rd-rend2/micropython/objtype.h"
	"${MPDir}/rd-rend2/micropython/objzip.c"
	"${MPDir}/rd-rend2/micropython/opmethods.c"
	"${MPDir}/rd-rend2/micropython/parse.c"
	"${MPDir}/rd-rend2/micropython/parse.h"
	"${MPDir}/rd-rend2/micropython/parsenum.c"
	"${MPDir}/rd-rend2/micropython/parsenum.h"
	"${MPDir}/rd-rend2/micropython/parsenumbase.c"
	"${MPDir}/rd-rend2/micropython/parsenumbase.h"
	"${MPDir}/rd-rend2/micropython/persistentcode.c"
	"${MPDir}/rd-rend2/micropython/persistentcode.h"
	"${MPDir}/rd-rend2/micropython/pystack.c"
	"${MPDir}/rd-rend2/micropython/pystack.h"
	"${MPDir}/rd-rend2/micropython/qstr.c"
	"${MPDir}/rd-rend2/micropython/qstr.h"
	"${MPDir}/rd-rend2/micropython/qstrdefs.h"
	"${MPDir}/rd-rend2/micropython/reader.c"
	"${MPDir}/rd-rend2/micropython/reader.h"
	"${MPDir}/rd-rend2/micropython/repl.c"
	"${MPDir}/rd-rend2/micropython/repl.h"
	"${MPDir}/rd-rend2/micropython/ringbuf.h"
	"${MPDir}/rd-rend2/micropython/runtime.c"
	"${MPDir}/rd-rend2/micropython/runtime.h"
	"${MPDir}/rd-rend2/micropython/runtime0.h"
	"${MPDir}/rd-rend2/micropython/runtime_utils.c"
	"${MPDir}/rd-rend2/micropython/scheduler.c"
	"${MPDir}/rd-rend2/micropython/scope.c"
	"${MPDir}/rd-rend2/micropython/scope.h"
	"${MPDir}/rd-rend2/micropython/sequence.c"
	"${MPDir}/rd-rend2/micropython/showbc.c"
	"${MPDir}/rd-rend2/micropython/smallint.c"
	"${MPDir}/rd-rend2/micropython/smallint.h"
	"${MPDir}/rd-rend2/micropython/stackctrl.c"
	"${MPDir}/rd-rend2/micropython/stackctrl.h"
	"${MPDir}/rd-rend2/micropython/stream.c"
	"${MPDir}/rd-rend2/micropython/stream.h"
	"${MPDir}/rd-rend2/micropython/unicode.c"
	"${MPDir}/rd-rend2/micropython/unicode.h"
	"${MPDir}/rd-rend2/micropython/vm.c"
	"${MPDir}/rd-rend2/micropython/vmentrytable.h"
	"${MPDir}/rd-rend2/micropython/vstr.c"
	"${MPDir}/rd-rend2/micropython/warning.c"
)
source_group("micropython" FILES ${MPRend2MicroPython})
set(MPRend2Files ${MPRend2Files} ${MPRend2MicroPython})

set(MPRend2MicroPythonExtMod
	"${MPDir}/rd-rend2/micropython/extmod/machine_i2c.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_i2c.h"
	"${MPDir}/rd-rend2/micropython/extmod/machine_mem.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_mem.h"
	"${MPDir}/rd-rend2/micropython/extmod/machine_pinbase.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_pinbase.h"
	"${MPDir}/rd-rend2/micropython/extmod/machine_pulse.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_pulse.h"
	"${MPDir}/rd-rend2/micropython/extmod/machine_signal.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_signal.h"
	"${MPDir}/rd-rend2/micropython/extmod/machine_spi.c"
	"${MPDir}/rd-rend2/micropython/extmod/machine_spi.h"
	"${MPDir}/rd-rend2/micropython/extmod/misc.h"
	"${MPDir}/rd-rend2/micropython/extmod/modbtree.c"
	"${MPDir}/rd-rend2/micropython/extmod/modframebuf.c"
	"${MPDir}/rd-rend2/micropython/extmod/modlwip.c"
	"${MPDir}/rd-rend2/micropython/extmod/modonewire.c"
	"${MPDir}/rd-rend2/micropython/extmod/modubinascii.c"
	"${MPDir}/rd-rend2/micropython/extmod/modubinascii.h"
	"${MPDir}/rd-rend2/micropython/extmod/moducryptolib.c"
	"${MPDir}/rd-rend2/micropython/extmod/moductypes.c"
	"${MPDir}/rd-rend2/micropython/extmod/moduhashlib.c"
	"${MPDir}/rd-rend2/micropython/extmod/moduheapq.c"
	"${MPDir}/rd-rend2/micropython/extmod/modujson.c"
	"${MPDir}/rd-rend2/micropython/extmod/modurandom.c"
	"${MPDir}/rd-rend2/micropython/extmod/modure.c"
	"${MPDir}/rd-rend2/micropython/extmod/moduselect.c"
	"${MPDir}/rd-rend2/micropython/extmod/modussl_axtls.c"
	"${MPDir}/rd-rend2/micropython/extmod/modussl_mbedtls.c"
	"${MPDir}/rd-rend2/micropython/extmod/modutimeq.c"
	"${MPDir}/rd-rend2/micropython/extmod/moduzlib.c"
	"${MPDir}/rd-rend2/micropython/extmod/modwebrepl.c"
	"${MPDir}/rd-rend2/micropython/extmod/modwebsocket.c"
	"${MPDir}/rd-rend2/micropython/extmod/modwebsocket.h"
	"${MPDir}/rd-rend2/micropython/extmod/uos_dupterm.c"
	"${MPDir}/rd-rend2/micropython/extmod/utime_mphal.c"
	"${MPDir}/rd-rend2/micropython/extmod/utime_mphal.h"
	"${MPDir}/rd-rend2/micropython/extmod/vfs.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs.h"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_fat.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_fat.h"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_fat_diskio.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_fat_file.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_posix.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_posix.h"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_posix_file.c"
	"${MPDir}/rd-rend2/micropython/extmod/vfs_reader.c"
	"${MPDir}/rd-rend2/micropython/extmod/virtpin.c"
	"${MPDir}/rd-rend2/micropython/extmod/virtpin.h"
)
source_group("micropython/extmod" FILES ${MPRend2MicroPythonExtMod})
set(MPRend2Files ${MPRend2Files} ${MPRend2MicroPythonExtMod})

set(MPRend2MicroPythonPortsMSVC
	"${MPDir}/rd-rend2/micropython/ports/msvc/dirent.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/dirent.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/fmode.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/fmode.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/gettimeofday.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/init.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/init.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/mpconfigport.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/realpath.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/realpath.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/sleep.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/sleep.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/unistd.h"
	"${MPDir}/rd-rend2/micropython/ports/msvc/windows_mphal.c"
	"${MPDir}/rd-rend2/micropython/ports/msvc/windows_mphal.h"
)
source_group("micropython/ports/msvc" FILES ${MPRend2MicroPythonPortsMSVC})
set(MPRend2Files ${MPRend2Files} ${MPRend2MicroPythonPortsMSVC})

set(MPRend2MicroPythonPortsUnix
	"${MPDir}/rd-rend2/micropython/ports/unix/alloc.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/coverage.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/fatfs_port.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/fdfile.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/gccollect.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/input.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/input.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/modffi.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modjni.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modmachine.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modos.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modtermios.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modtime.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/moduos_vfs.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/moduselect.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/modusocket.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport_coverage.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport_fast.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport_freedos.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport_minimal.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpconfigport_nanbox.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mphalport.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpthreadport.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/mpthreadport.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/qstrdefsport.h"
	"${MPDir}/rd-rend2/micropython/ports/unix/unix_file.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/unix_main.c"
	"${MPDir}/rd-rend2/micropython/ports/unix/unix_mphal.c"
)
source_group("micropython/ports/unix" FILES ${MPRend2MicroPythonPortsUnix})
set(MPRend2Files ${MPRend2Files} ${MPRend2MicroPythonPortsUnix})

set(MPRend2RdCommonFiles
	"${MPDir}/rd-common/mdx_format.h"
	"${MPDir}/rd-common/tr_common.h"
	"${MPDir}/rd-common/tr_font.cpp"
	"${MPDir}/rd-common/tr_font.h"
	"${MPDir}/rd-common/tr_image_load.cpp"
	"${MPDir}/rd-common/tr_image_jpg.cpp"
	"${MPDir}/rd-common/tr_image_tga.cpp"
	"${MPDir}/rd-common/tr_image_png.cpp"
	"${MPDir}/rd-common/tr_noise.cpp"
	"${MPDir}/rd-common/tr_public.h"
	"${MPDir}/rd-common/tr_types.h")
source_group("rd-common" FILES ${MPRend2RdCommonFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2RdCommonFiles})

set(MPRend2CommonFiles
	"${MPDir}/qcommon/matcomp.cpp"
	"${MPDir}/qcommon/q_shared.cpp"
	"${SharedCommonFiles}")
source_group("common" FILES ${MPRend2CommonFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2CommonFiles})

set(MPRend2CommonSafeFiles
	${SharedCommonSafeFiles}
	)
source_group("common/safe" FILES ${MPRend2CommonSafeFiles})
set(MPRend2Files ${MPRend2Files} ${MPRend2CommonSafeFiles})

# Transparently use either bundled or system libjpeg.
list(APPEND MPRend2IncludeDirectories ${JPEG_INCLUDE_DIR})
list(APPEND MPRend2Libraries          ${JPEG_LIBRARIES})

# Transparently use either bundled or system libpng.  Order is important --
# libpng used zlib, so it must come before it on the linker command line.
list(APPEND MPRend2IncludeDirectories ${PNG_INCLUDE_DIRS})
list(APPEND MPRend2Libraries          ${PNG_LIBRARIES})

# Transparently use either bundled or system zlib.
list(APPEND MPRend2IncludeDirectories ${ZLIB_INCLUDE_DIR})
list(APPEND MPRend2Libraries          ${ZLIB_LIBRARIES})

# Transparently use our bundled minizip.
list(APPEND MPRend2IncludeDirectories ${MINIZIP_INCLUDE_DIRS})
list(APPEND MPRend2Libraries          ${MINIZIP_LIBRARIES})

find_package(OpenGL REQUIRED)
set(MPRend2IncludeDirectories ${MPRend2IncludeDirectories} ${OPENGL_INCLUDE_DIR})
set(MPRend2Libraries ${MPRend2Libraries} ${OPENGL_LIBRARIES})

source_group("renderer"
	FILES
	${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.h
	${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.cpp)
set(MPRend2Files
	${MPRend2Files}
	${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.h
	${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.cpp)

set(MPRend2IncludeDirectories ${MPRend2IncludeDirectories} ${OpenJKLibDir})
add_library(${MPRend2} SHARED ${MPRend2Files})

if(NOT MSVC)
	# remove "lib" prefix for .so/.dylib files
	set_target_properties(${MPRend2} PROPERTIES PREFIX "")
endif()

if(WIN32)
	install(TARGETS ${MPRend2}
		RUNTIME
		DESTINATION ${JKAInstallDir}
		COMPONENT ${JKAMPClientComponent})
else(WIN32)
	if(MakeApplicationBundles AND BuildMPEngine)
		install(TARGETS ${MPRend2}
			LIBRARY
			DESTINATION "${JKAInstallDir}/${MPEngine}.app/Contents/MacOS/"
			COMPONENT ${JKAMPClientComponent})
	else()
		install(TARGETS ${MPRend2}
			LIBRARY
			DESTINATION ${JKAInstallDir}
			COMPONENT ${JKAMPClientComponent})
	endif()
endif()

set_target_properties(${MPRend2} PROPERTIES COMPILE_DEFINITIONS "${SharedDefines}")

# Hide symbols not explicitly marked public.
set_property(TARGET ${MPRend2} APPEND PROPERTY COMPILE_OPTIONS ${OPENJK_VISIBILITY_FLAGS})
set_target_properties(${MPRend2} PROPERTIES INCLUDE_DIRECTORIES "${MPRend2IncludeDirectories}")
set_target_properties(${MPRend2} PROPERTIES PROJECT_LABEL "MP Rend2 Renderer")
target_link_libraries(${MPRend2} ${MPRend2Libraries})
target_include_directories(${MPRend2} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


target_include_directories(${MPRend2} PRIVATE "${MPDir}/rd-rend2/micropython/ports/msvc/")

# GLSL shader file generator
add_executable(compact_glsl
	${MPDir}/rd-rend2/glsl/compact.cpp
	${MPDir}/rd-rend2/tr_allocator.cpp
	${MPDir}/rd-rend2/tr_allocator.h
	${MPDir}/rd-rend2/tr_glsl_parse.cpp)
target_compile_definitions(compact_glsl PRIVATE "GLSL_BUILDTOOL")
if (NOT WIN32 AND NOT APPLE)
	target_compile_definitions(compact_glsl PRIVATE "ARCH_STRING=\"${Architecture}\"")
endif()
target_include_directories(compact_glsl PRIVATE "${MPRend2IncludeDirectories}")
add_custom_command(
	OUTPUT
		${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.cpp
		${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.h
	COMMAND
		compact_glsl
			${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.cpp
			${CMAKE_CURRENT_BINARY_DIR}/glsl_shaders.h
			${MPRend2GLSLFiles}
	DEPENDS
		compact_glsl ${MPRend2GLSLFiles})
