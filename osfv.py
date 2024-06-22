import pandas as pd
import scipy.stats as stats

# Data
data = {'Handphone': ['A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C'],
        'Layak': [0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1]}

df = pd.DataFrame(data)

# Crosstab
ctab = pd.crosstab(df['Handphone'], df['Layak'])

# Chi-Square Test
chi2, p, dof, expected = stats.chi2_contingency(ctab)

chi2, p

