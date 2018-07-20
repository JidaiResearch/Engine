#ifndef RIP_REFIMPORT
#define RIP_REFIMPORT

#include <qcommon/q_shared.h>
#include <sys/sys_public.h>
#include <qcommon/MiniHeap.h>

void				FS_FreeFile(void *buffer);
void				FS_FreeFileList(char **fileList);
int					FS_Read(void *buffer, int len, fileHandle_t f);
long				FS_ReadFile(const char *qpath, void **buffer);
void				FS_FCloseFile(fileHandle_t f);
long				FS_FOpenFileRead(const char *qpath, fileHandle_t *file, qboolean uniqueFILE);
fileHandle_t		FS_FOpenFileWrite(const char *qpath, qboolean safe);
int					FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode);
qboolean			FS_FileExists(const char *file);
int					FS_FileIsInPAK(const char *filename, int *pChecksum);
char **				FS_ListFiles(const char *directory, const char *extension, int *numfiles);
int					FS_Write(const void *buffer, int len, fileHandle_t f);
void				FS_WriteFile(const char *qpath, const void *buffer, int size);


void     CM_BoxTrace          ( trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, int capsule );
void     CM_DrawDebugSurface  ( void (*drawPoly)(int color, int numPoints, float *points) );
bool     CM_CullWorldBox      ( const cplane_t *frustum, const vec3pair_t bounds );
byte *   CM_ClusterPVS        ( int cluster );
int      CM_LeafArea          ( int leafnum );
int      CM_LeafCluster       ( int leafnum );
int      CM_PointLeafnum      ( const vec3_t p );
int      CM_PointContents     ( const vec3_t p, clipHandle_t model );


typedef void (*xcommand_t) (void);
void   Cmd_ExecuteString    ( const char *text                                           );
int    Cmd_Argc             ( void                                                       );
char * Cmd_Argv             ( int arg                                                    );
void   Cmd_ArgsBuffer       ( char *buffer, int bufferLength                             );
void   Cmd_AddCommand       ( const char *cmd_name, xcommand_t function, const char *desc);
void   Cmd_RemoveCommand    ( const char *cmd_name                                       );


cvar_t * Cvar_Set               ( const char *var_name, const char *value                                      );
//cvar_t * Cvar_Get               ( const char *var_name, const char *value, uint32_t flags, const char *var_desc);
cvar_t *Cvar_SetValue           ( const char *name, float value                                                );
void Cvar_CheckRange            ( cvar_t *cv, float minVal, float maxVal, qboolean shouldBeIntegral            );
void Cvar_VariableStringBuffer  ( const char *var_name, char *buffer, int bufsize                              );
char * Cvar_VariableString      ( const char *var_name                                                         );
float Cvar_VariableValue        ( const char *var_name                                                         );
int Cvar_VariableIntegerValue   ( const char *var_name                                                         );



	qboolean   Com_TheHunkMarkHasBeenMade( void                                                         );
	void       S_RestartMusic( void                                                                     );
	qboolean   SND_RegisterAudio_LevelLoadEnd( qboolean bDeleteEverythingNotUsedThisLevel               );
	e_status   CIN_RunCinematic( int handle                                                             );
	int        CIN_PlayCinematic( const char *arg0, int xpos, int ypos, int width, int height, int bits );
	void       CIN_UploadCinematic( int handle                                                          );
	void       CL_WriteAVIVideoFrame( const byte *imageBuffer, int size                                 );
	char *     GetSharedMemory( void                                                                    );
	//vm_t *     GetCurrentVM( void                                                                       );
	qboolean   CGVMLoaded( void                                                                         );
	int        CGVM_RagCallback( int callType                                                           );
	window_t   WIN_Init( const windowDesc_t *desc, glconfig_t *glConfig                                 );
	void       WIN_SetGamma( glconfig_t *glConfig, byte red[256], byte green[256], byte blue[256]       );
	void       WIN_Present( window_t *window                                                            );
	void       WIN_Shutdown( void                                                                       );
	void *     GL_GetProcAddress( const char *name                                                      );
	qboolean   GL_ExtensionSupported( const char *extension                                             );




	void *          CM_GetCachedMapDiskImage       ( void                                             ); 
	void            CM_SetCachedMapDiskImage       ( void *ptr                                        ); 
	void            CM_SetUsingCache               ( qboolean usingCache                              ); 
	IHeapAllocator *GetG2VertSpaceServer           ( void                                             ); 
	bool            PD_Store                       ( const char *name, const void *data, size_t size  ); 
	const void *    PD_Load                        ( const char *name, size_t *size                   ); 
	int             Key_GetCatcher                 (                                                  ); 
	const char *    Clipboard_Get                  (                                                  ); 
	void            Clipboard_Set                  ( const char *text                                 ); 
	void            micropython_init               (                                                  ); 
	void            micropython_eval               ( char *code                                       );

void R_Printf(int printLevel, const char *fmt, ...);

#endif