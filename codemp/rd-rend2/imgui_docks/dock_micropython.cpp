#include "dock_micropython.h"
#include "../imgui/include_imgui.h"
//#include <client/client.h>
#include "dock_console.h"
//#include <include_duktape.h>
#include <string>

bool IsKeyPressedMap(ImGuiKey key, bool repeat);
void SaveIniSettingsToDisk(const char* ini_filename); // was a static function in ImGui
void ImStrncpy(char* dst, const char* src, int count);



#define MICROPY_NLR_SETJMP (1)

extern "C" {
#include "micropython/nlr.h"
#include "micropython/compile.h"
#include "micropython/runtime.h"
#include "micropython/gc.h"
#include <micropython/stackctrl.h>
}

//typedef void (*type_callback_repl)(int, int, char *);
//type_callback_repl callback_repl_node;
//CCALL void set_callback_repl_node(type_callback_repl cb) {
//	callback_repl_node = cb;
//}

DockMicroPython::DockMicroPython() {
}

const char *DockMicroPython::label() {
	return "MicroPython";
}

static int repl_callback(ImGuiTextEditCallbackData *data) {
	DockMicroPython *dock = (DockMicroPython *)data->UserData;
	if (ImGui::GetIO().KeyCtrl && ImGui::IsKeyPressed(' ', false)) {
		char returnbuffer[256] = {0};
		//js_call(ctx, "get_auto_completion", "siiii", dock->replbuffer, data->CursorPos, data->SelectionStart, data->SelectionEnd, returnbuffer);
		//imgui_log("got returnbuffer: %s\n", returnbuffer);
		data->InsertChars(data->CursorPos, returnbuffer);
	}
	//log("callback called\n");
	return 0;
}


static char heap[16384];

mp_obj_t execute_from_str(const char *str) {
	nlr_buf_t nlr;
	if (nlr_push(&nlr) == 0) {
		mp_lexer_t *lex = mp_lexer_new_from_str_len(0/*MP_QSTR_*/, str, strlen(str), false);
		mp_parse_tree_t pt = mp_parse(lex, MP_PARSE_FILE_INPUT);
		mp_obj_t module_fun = mp_compile(&pt, lex->source_name, MP_EMIT_OPT_NONE, false);
		mp_call_function_0(module_fun);
		nlr_pop();
		return 0;
	}
	else {
		// uncaught exception
		return (mp_obj_t)nlr.ret_val;
	}
}
#define BYTES_PER_WORD (sizeof(mp_uint_t))

extern "C" int main_py(int argc, char **argv);
extern "C" int execute_from_lexer(int source_kind, const void *source, mp_parse_input_kind_t input_kind, bool is_repl);
#define LEX_SRC_STR (1)
#define LEX_SRC_VSTR (2)
#define LEX_SRC_FILENAME (3)
#define LEX_SRC_STDIN (4)


void DockMicroPython::imgui() {
	ImGui::InputTextMultiline("", replbuffer, sizeof replbuffer, ImGui::GetWindowSize() + ImVec2(-15, -35 - 20), ImGuiInputTextFlags_CallbackAlways | ImGuiInputTextFlags_AllowTabInput, repl_callback, (void *)this);

	if (ImGui::GetIO().KeyCtrl && ImGui::IsKeyPressed('r', false)) {
		//js_call(ctx, "reload", "");
		imgui_log("dock_node.cpp> todo: reload node's .js files \n");
	}
	
	if (ImGui::IsItemActive()) {
		//log("active\n");
		/*
		comment this shit in imgui.c to make this work:
		bool ctrl_enter_for_new_line = (flags & ImGuiInputTextFlags_CtrlEnterForNewLine) != 0;
        if (!is_multiline || (ctrl_enter_for_new_line && !io.KeyCtrl) || (!ctrl_enter_for_new_line && io.KeyCtrl))
        {
            //SetActiveID(0);
            //enter_pressed = true;
        }
		*/
		if (ImGui::GetIO().KeyCtrl && ImGui::IsKeyPressed('s', false)) {
			ImGuiContext *g = ImGui::GetCurrentContext();
			int select_start = g->InputTextState.StbState.select_start;
			int select_end = g->InputTextState.StbState.select_end;
			if (select_start == select_end) {
				select_start = g->InputTextState.StbState.cursor;
				select_end = g->InputTextState.StbState.cursor;
			}
			imgui_log("save dock\n");
#ifdef EMSCRIPTEN
			EM_ASM_({
			  callback_repl_ctrl_s($0, $1, $2);
			}, select_start, select_end, replbuffer);
#endif
		}

		if (ImGui::GetIO().KeyAlt && IsKeyPressedMap(ImGuiKey_Enter, 0)) {
			ImGuiContext *g = ImGui::GetCurrentContext();
			int select_start = g->InputTextState.StbState.select_start;
			int select_end = g->InputTextState.StbState.select_end;
			if (select_start == select_end) {
				select_start = g->InputTextState.StbState.cursor;
				select_end = g->InputTextState.StbState.cursor;
			}
			//imgui_log("execute full line\n");
#ifdef EMSCRIPTEN
			EM_ASM_({
			  callback_repl_alt_enter($0, $1, $2);
			}, select_start, select_end, replbuffer);
#endif

		}
		if (ImGui::GetIO().KeyCtrl && IsKeyPressedMap(ImGuiKey_Enter, 0)) {
			ImGuiContext *g = ImGui::GetCurrentContext();
			int select_start = g->InputTextState.StbState.select_start;
			int select_end = g->InputTextState.StbState.select_end;
			if (select_start == select_end) {
				select_start = g->InputTextState.StbState.cursor;
				select_end = g->InputTextState.StbState.cursor;
			}

#ifdef EMSCRIPTEN
			EM_ASM_({
			  callback_repl($0, $1, $2);
			}, select_start, select_end, replbuffer);
#else


			static int first = 1;
			if (first) {
				first = 0;
				//// Initialized stack limit
				//mp_stack_set_limit(40000 * (BYTES_PER_WORD / 4));
				//// Initialize heap
				//gc_init(heap, heap + sizeof(heap));
				//
				//#if MICROPY_ENABLE_PYSTACK
				//static mp_obj_t pystack[1024];
				//mp_pystack_init(pystack, &pystack[MP_ARRAY_SIZE(pystack)]);
				//#endif
				//
				//// Initialize interpreter
				//mp_init();
				//
				//const char str[] = "print('Hello world of easy embedding!')";
				//if (execute_from_str(str)) {
				//	imgui_log("Error\n");
				//}
				main_py(0, NULL);
				//execute_from_lexer(LEX_SRC_STDIN, "print('Hello world of easy embedding!')", MP_PARSE_SINGLE_INPUT, true);
			}
			//execute_from_lexer(LEX_SRC_STDIN, replbuffer, MP_PARSE_SINGLE_INPUT, true);
			//execute_from_lexer(LEX_SRC_STR, "print('Hello world of easy embedding!')", MP_PARSE_SINGLE_INPUT, true);
			execute_from_lexer(LEX_SRC_STR, replbuffer, MP_PARSE_SINGLE_INPUT, true);
			//execute_from_str(replbuffer);

			//if (callback_repl_node) {
			//	callback_repl_node(select_start, select_end, replbuffer);
			//} else {
			//	imgui_log("dock_node.cpp, set callback_repl_node via ffi first\n");
			//}
#endif
		}

	}

	ImGui::InputText("Filename", repl_filename, sizeof repl_filename);
	ImGui::SameLine(0, 5);
	if (ImGui::Button("Save")) {
		//if (file_put_contents(repl_filename, replbuffer, strlen(replbuffer))) {
		//	imgui_log("[success] REPL content saved to %s\n", repl_filename);
		//} else {
		//	imgui_log("[fail] couldnt save %s\n", repl_filename);
		//}
		//js_call(ctx, "file_put_contents", "ss", repl_filename, replbuffer);
	}
	ImGui::SameLine(0, 5);
	if (ImGui::Button("Load")) {
		//auto meh = &replbuffer;
		//char *buffer;
		//size_t buffer_length;
		//if (file_get_contents(repl_filename, &buffer, &buffer_length)) {
		//	imgui_log("[success] REPL content loaded from %s\n", repl_filename);
		//	strncpy(replbuffer, buffer, buffer_length);
		//	free(buffer);
		//} else {
		//	imgui_log("[fail] couldnt load %s\n", repl_filename);
		//}
		//js_eval((char *)std::string("repl_set_text(file_get_contents(\""+std::string(repl_filename)+"\"))").c_str());
	}
}