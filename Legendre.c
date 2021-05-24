void Legendre(int n, int m, double fi, double** pnm, double** dpnm)
{


	double** aux_pnm = matrizZeros(n + 2, m + 2);
	double** aux_dpnm = matrizZeros(n + 2, m + 2);
	aux_pnm[1][1] = 1;
	aux_dpnm[1][1] = 0;
	aux_pnm[2][2] = sqrt(3) * cos(fi);
	aux_dpnm[2][2] = -sqrt(3) * sin(fi);



	for (int i = 2; i <= n; i++)
	{
		aux_pnm[i + 1][i + 1] = sqrt((2.0 * i + 1) / (2.0 * i)) * cos(fi) * aux_pnm[i][i];
	}

	for (int i = 2; i <= n; i++)
	{
		aux_dpnm[i + 1][i + 1] = sqrt((2.0 * i + 1) / (2.0 * i)) * ((cos(fi) * aux_dpnm[i][i]) - (sin(fi) * aux_pnm[i][i]));
	}



	for (int i = 1; i <= n; i++)
	{
		aux_pnm[i + 1][i] = sqrt(2.0 * i + 1) * sin(fi) * aux_pnm[i][i];
	}

	for (int i = 1; i <= n; i++)
	{
		aux_dpnm[i + 1][i] = sqrt(2.0 * i + 1) * ((cos(fi) * aux_pnm[i][i]) + (sin(fi) * aux_dpnm[i][i]));
	}



	int j = 0, k = 2;

	while (1)
	{
		for (int i = k; i <= n; i++)
		{
			aux_pnm[i + 1][j + 1] = sqrt((2.0 * i + 1) / ((1.0 * i - j) * (1.0 * i + j))) * ((sqrt(2.0 * i - 1) * sin(fi) * aux_pnm[i][j + 1]) - (sqrt(((1.0 * i + j - 1.0) * (1.0 * i - j - 1.0)) / (2.0 * i - 3)) * aux_pnm[i - 1][j + 1]));
		}

		j = j + 1;

		k = k + 1;

		if (j > m)
		{
			break;
		}
	}

	j = 0;
	k = 2;

	while (1)
	{
		for (int i = k; i <= n; i++)
		{
			aux_dpnm[i + 1][j + 1] = sqrt((2.0 * i + 1) / ((1.0 * i - 1.0 * j) * (1.0 * i + j))) * ((sqrt(2.0 * i - 1) * sin(fi) * aux_dpnm[i][j + 1]) + (sqrt(2.0 * i - 1) * cos(fi) * aux_pnm[i][j + 1]) - (sqrt(((1.0 * i + j - 1.0) * (1.0 * i - j - 1.0)) / (2.0 * i - 3)) * aux_dpnm[i - 1][j + 1]));
		}

		j = j + 1;

		k = k + 1;

		if (j > m)
		{
			break;
		}
	}



	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			pnm[i][j] = aux_pnm[i + 1][j + 1];
			dpnm[i][j] = aux_dpnm[i + 1][j + 1];
		}
	}

	liberarMatriz(aux_pnm, n + 2, m + 2);
	liberarMatriz(aux_dpnm, n + 2, m + 2);



}void Legendre(int n, int m, double fi, double** pnm, double** dpnm)
{



	double** aux_pnm = matrizZeros(n + 2, m + 2);
	double** aux_dpnm = matrizZeros(n + 2, m + 2);
	aux_pnm[1][1] = 1;
	aux_dpnm[1][1] = 0;
	aux_pnm[2][2] = sqrt(3) * cos(fi);
	aux_dpnm[2][2] = -sqrt(3) * sin(fi);



	for (int i = 2; i <= n; i++)
	{
		aux_pnm[i + 1][i + 1] = sqrt((2.0 * i + 1) / (2.0 * i)) * cos(fi) * aux_pnm[i][i];
	}

	for (int i = 2; i <= n; i++)
	{
		aux_dpnm[i + 1][i + 1] = sqrt((2.0 * i + 1) / (2.0 * i)) * ((cos(fi) * aux_dpnm[i][i]) - (sin(fi) * aux_pnm[i][i]));
	}



	for (int i = 1; i <= n; i++)
	{
		aux_pnm[i + 1][i] = sqrt(2.0 * i + 1) * sin(fi) * aux_pnm[i][i];
	}

	for (int i = 1; i <= n; i++)
	{
		aux_dpnm[i + 1][i] = sqrt(2.0 * i + 1) * ((cos(fi) * aux_pnm[i][i]) + (sin(fi) * aux_dpnm[i][i]));
	}



	int j = 0, k = 2;

	while (1)
	{
		for (int i = k; i <= n; i++)
		{
			aux_pnm[i + 1][j + 1] = sqrt((2.0 * i + 1) / ((1.0 * i - j) * (1.0 * i + j))) * ((sqrt(2.0 * i - 1) * sin(fi) * aux_pnm[i][j + 1]) - (sqrt(((1.0 * i + j - 1.0) * (1.0 * i - j - 1.0)) / (2.0 * i - 3)) * aux_pnm[i - 1][j + 1]));
		}

		j = j + 1;

		k = k + 1;

		if (j > m)
		{
			break;
		}
	}

	j = 0;
	k = 2;

	while (1)
	{
		for (int i = k; i <= n; i++)
		{
			aux_dpnm[i + 1][j + 1] = sqrt((2.0 * i + 1) / ((1.0 * i - 1.0 * j) * (1.0 * i + j))) * ((sqrt(2.0 * i - 1) * sin(fi) * aux_dpnm[i][j + 1]) + (sqrt(2.0 * i - 1) * cos(fi) * aux_pnm[i][j + 1]) - (sqrt(((1.0 * i + j - 1.0) * (1.0 * i - j - 1.0)) / (2.0 * i - 3)) * aux_dpnm[i - 1][j + 1]));
		}

		j = j + 1;

		k = k + 1;

		if (j > m)
		{
			break;
		}
	}



	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			pnm[i][j] = aux_pnm[i + 1][j + 1];
			dpnm[i][j] = aux_dpnm[i + 1][j + 1];
		}
	}

	liberarMatriz(aux_pnm, n + 2, m + 2);
	liberarMatriz(aux_dpnm, n + 2, m + 2);
}