import md5

meu_md5 = None
SAL = "alemao"
senha = raw_input("Entre Com Sua Senha:")
meu_md5 = md5.new(SAL+senha).hexdigest()
while senha != meu_md5:
	senha = raw_input("Entre Com Sua Senha Para Sair:")
	senha = md5.new(SAL+senha).hexdigest()