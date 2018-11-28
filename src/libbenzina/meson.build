#
# Library: libbenzina
#
# Contains a lot of the "generic" logic for data-loading, as well as ProtoBuf
# parsing code.
#

libbenzinaSrcs  = files('benzina.c', 'benzinaproto.c')
libbenzinaDeps  = [threadsDep, libm, libdl, librt]
libbenzinaIncs  = [benzinaIncs]
libbenzinaCArgs = ['-DBENZINA_IS_BUILDING=1',
                   '-DBENZINA_IS_SHARED=1']
libbenzinaSha   = shared_library('benzina',             libbenzinaSrcs,
                                 include_directories  : libbenzinaIncs,
                                 dependencies         : libbenzinaDeps,
                                 c_args               : libbenzinaCArgs,
                                 link_with            : [],
                                 gnu_symbol_visibility: 'hidden',
                                 build_rpath          : librpath,
                                 install_rpath        : librpath,
                                 install              : true,
                                 install_dir          : libdir)
