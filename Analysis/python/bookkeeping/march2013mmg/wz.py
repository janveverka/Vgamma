from Vgamma.Analysis.records.montecarlosamplerecord import MonteCarloSampleRecord
from Vgamma.Analysis.tools import load_input_files


wz = MonteCarloSampleRecord(
    name = 'wz',
    title = 'WZ_TuneZ2_Fall11',
    latex_label = 'WZ',
    source_filenames = load_input_files('MC/wz_hadoop.dat'),
    source_tree       = 'VgAnalyzerKit/EventTree',
    skim_filenames = load_input_files('MC/mmg_wz_hadoop.dat'),
    skim_tree         = 'EventTree',
    tree_version      = 'V14MC',
    ## AN-11-251 rev 153517, p. 7
    cross_section_in_pb = 18.2,
    )

wz.total_processed_events = 4165243
